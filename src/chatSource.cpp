#include "chatSource.h"

static const char * chatSourceGetName(void * unused)
{
    UNUSED_PARAMETER(unused);

    return obs_module_text("ChatSource");
}

static void * chatSourceCreate(obs_data_t * settings, obs_source_t * source)
{
    UNUSED_PARAMETER(settings);
    UNUSED_PARAMETER(source);
}

static void chatSourceDestroy(void * data)
{
    UNUSED_PARAMETER(data);
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
    /* To be implemented                        Signatures
    -------------------------------------------------------------------------------
    .update = chatSourceUpdate,              // static void (void * data, obs_data_t * settings)
    .get_defaults = chatSourceDefaults,      // static void (obs_data_t * settings)
    .show = chatSourceShow,                  // static void (void * data)
    .hide = chatSourceHide,                  // static void (void * data)
    .video_render = chatSourceRender,        // static void (void * data, gs_effect_t * effect)
    .video_tick = chatSourceTick,            // static void (void * data, float seconds)
    .get_properties = chatSourceProperties,  // static obs_properties_t * (void * data)
    .activate = chatSourceActivate,          // static void (void * data)
    */
    .icon_type = OBS_ICON_TYPE_TEXT,
};
