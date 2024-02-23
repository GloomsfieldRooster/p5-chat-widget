#pragma once

#include <vector>
#include <obs-module.h>
#include <plugin-support.h>

struct chatSource
{
    uint32_t width;
    uint32_t height;

    obs_source_t * source;
    obs_source_t * textSource;

    obs_data_t * textSettings;
};

