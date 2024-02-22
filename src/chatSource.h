#pragma once

#include <obs-module.h>
#include <plugin-support.h>

struct chatSource
{
    uint32_t width;
    uint32_t height;

    obs_source_t * source;
};

