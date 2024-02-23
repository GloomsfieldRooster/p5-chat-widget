#include "chatSource.h"

static const char * chatSourceGetName(void * unused)
{
    UNUSED_PARAMETER(unused);

    return obs_module_text("Chat Source");
}

static void chatSourceUpdate(void * data, obs_data_t * settings)
{
    chatSource * source = static_cast<chatSource *>(data);

    uint32_t width = (uint32_t)obs_data_get_int(settings, "width");
    uint32_t height = (uint32_t)obs_data_get_int(settings, "height");

    source->width = width;
    source->height = height;

    obs_data_set_string(source->textSettings, "text", "test2");
    obs_source_update(source->textSource, source->textSettings);
}

static void * chatSourceCreate(obs_data_t * settings, obs_source_t * source)
{
    chatSource * newChatSource = new chatSource;
    newChatSource->source = source;

    newChatSource->textSettings = obs_data_create();
    obs_data_set_string(newChatSource->textSettings, "text", "test1");

    newChatSource->textSource = obs_source_create_private("text_ft2_source", "test", newChatSource->textSettings);

    obs_source_add_active_child(newChatSource->source, newChatSource->textSource);

    chatSourceUpdate(newChatSource, settings);

    return newChatSource;
}

static void chatSourceDestroy(void * data)
{
    chatSource * source = static_cast<chatSource *>(data);

    obs_source_remove(source->textSource);
    obs_source_release(source->textSource);
    source->textSource = nullptr;

    obs_data_release(source->textSettings);
    source->textSettings = nullptr;

    delete source;
}

static uint32_t chatSourceGetWidth(void * data)
{
    chatSource * source = static_cast<chatSource *>(data);
    return source->width;
}

static uint32_t chatSourceGetHeight(void * data)
{
    chatSource * source = static_cast<chatSource *>(data);
    return source->height;
}

static void chatSourceActivate(void * data)
{
    UNUSED_PARAMETER(data);
}

static void chatSourceRender(void * data, gs_effect_t * effect)
{
    UNUSED_PARAMETER(effect);

    chatSource * source = static_cast<chatSource *>(data);
    
    obs_source_video_render(source->textSource);
}

static void chatSourceDefaults(obs_data_t * settings)
{
    obs_data_set_default_int(settings, "width", 320);
    obs_data_set_default_int(settings, "height", 1080);
}

static void chatSourceShow(void * data)
{
    UNUSED_PARAMETER(data);
}

static void chatSourceHide(void * data)
{
    UNUSED_PARAMETER(data);
}

static void chatSourceTick(void * data, float seconds)
{
    UNUSED_PARAMETER(data);
    UNUSED_PARAMETER(seconds);
}

static obs_properties_t * chatSourceProperties(void * data)
{
    UNUSED_PARAMETER(data);

    obs_properties_t * properties = obs_properties_create();

    obs_properties_add_text(properties, "username", obs_module_text("Username"), OBS_TEXT_DEFAULT);
    obs_properties_add_int(properties, "width", obs_module_text("Width"), 0, 4096, 1);
    obs_properties_add_int(properties, "height", obs_module_text("Height"), 0, 4096, 1);

    return properties;
}

struct obs_source_info chatSourceInfo
{
    .id = "p5_chat_source",
    .type = OBS_SOURCE_TYPE_INPUT,
    .output_flags = OBS_SOURCE_VIDEO,
    .get_name = chatSourceGetName,           // static const char * (void * unused)
    .create = chatSourceCreate,              // static void * (obs_data_t * settings, obs_source_t * source)
    .destroy = chatSourceDestroy,            // static void (void * data)
    .get_width = chatSourceGetWidth,         // static uint32_t (void * data)
    .get_height = chatSourceGetHeight,       // static uint32_t (void * data)
    .update = chatSourceUpdate,              // static void (void * data, obs_data_t * settings)
    .activate = chatSourceActivate,          // static void (void * data)
    .video_render = chatSourceRender,        // static void (void * data, gs_effect_t * effect)
    .get_defaults = chatSourceDefaults,      // static void (obs_data_t * settings)
    .show = chatSourceShow,                  // static void (void * data)
    .hide = chatSourceHide,                  // static void (void * data)
    .video_tick = chatSourceTick,            // static void (void * data, float seconds)
    .get_properties = chatSourceProperties,  // static obs_properties_t * (void * data)
    .icon_type = OBS_ICON_TYPE_TEXT,
};
