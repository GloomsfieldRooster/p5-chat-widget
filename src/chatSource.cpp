#include "chatSource.h"

struct obs_source_info chatSourceInfo
{
    .id = "p5_chat_source",
    .type = OBS_SOURCE_TYPE_INPUT,
    .output_flags = OBS_SOURCE_VIDEO,
    .icon_type = OBS_ICON_TYPE_TEXT,
    /* To be implemented                        Signatures
    -------------------------------------------------------------------------------
    .get_name = chatSourceGetName,           // static const char * (void * unused)
    .create = chatSourceCreate,              // static void * (obs_data_t * settings, obs_source_t * source)
    .get_width = chatSourceGetWidth,         // static uint32_t (void * data)
    .get_height = chatSourceGetHeight,       // static uint32_t (void * data)
    .update = chatSourceUpdate,              // static void (void * data, obs_data_t * settings)
    .destroy = chatSourceDestroy             // static void (void * data)
    .get_defaults = chatSourceDefaults,      // static void (obs_data_t * settings)
    .show = chatSourceShow,                  // static void (void * data)
    .hide = chatSourceHide,                  // static void (void * data)
    .video_render = chatSourceRender,        // static void (void * data, gs_effect_t * effect)
    .video_tick = chatSourceTick,            // static void (void * data, float seconds)
    .get_properties = chatSourceProperties,  // static obs_properties_t * (void * data)
    .activate = chatSourceActivate,          // static void (void * data)
    */
};
