/*
 * Filename: ecs_color.c
 * Path: source/utils
 * Created Date: Saturday, September 30th 2023, 6:42:38 pm
 * Author: osvegn
 * 
 * Copyright (c) 2023 ECS
 */

#include "utils/ecs_color.h"

void copy_color(ecs_color_t *dest, ecs_color_t *src)
{
    *dest = *src;
}

void set_color(ecs_color_t *color, uchar r, uchar g, uchar b)
{
    color->r = r;
    color->g = g;
    color->b = b;
}

void set_alpha(ecs_color_t *color, uchar alpha)
{
    color->a = alpha;
}
