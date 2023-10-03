/*
 * Filename: ecs_graphics.c
 * Path: sources/utils
 * Created Date: Saturday, September 30th 2023, 5:01:43 pm
 * Author: osvegn
 * 
 * Copyright (c) 2023 ECS
 */

#include "utils/ecs_graphics.h"
#include <stdlib.h>
#include <string.h>

int set_shape_color(shape_t *shape, ecs_color_t *color, shape_color_t type)
{
    if (!shape || !color)
        return -1;
    shape->color[type] = *color;
    return 0;
}

ecs_color_t *get_shape_color(shape_t *shape, shape_color_t type)
{
    if (!shape)
        return 0;
    return &shape->color[type];
}

int set_shape_thickness(shape_t *shape, float value)
{
    if (!shape)
        return -1;
    shape->thickness = value;
    return 0;
}

float get_shape_thickness(shape_t *shape)
{
    if (!shape)
        return -1;
    return shape->thickness;
}

int set_shape_is_filled(shape_t *shape, bool value)
{
    if (!shape)
        return -1;
    shape->is_filled = value;
    return 0;
}

bool get_shape_is_filled(shape_t *shape)
{
    return shape->is_filled;
}

int shape_constructor(shape_t *shape, int point_number)
{
    for (unsigned int i = 0; i < MAX; i++) {
        shape->color[i] = (ecs_color_t){0, 0, 0, 0};
    }
    shape->thickness = 1.0f;
    shape->is_filled = true;
    return vector_constructor(&shape->points, sizeof(ecs_vector2f_t), point_number);
}

int shape_destructor(shape_t *shape)
{
    shape->points.destructor(&shape->points);
    if (shape->texture_filename)
        free(shape->texture_filename);
    return 0;
}

int set_shape_points(shape_t *shape, vector_t *points)
{
    if (!shape || !points)
        return -1;
    shape->points = *points;
    return 0;
}

int set_shape_point(shape_t *shape, ecs_vector2f_t *point, int index)
{
    if (!shape || !point)
        return -1;
    shape->points.emplace(&shape->points, point, index);
    return 0;
}

int set_texture_filename(shape_t *shape, char *filename)
{
    if (!shape || !filename)
        return -1;
    shape->texture_filename = strdup(filename);
    return 0;
}

char *get_texture_filename(shape_t *shape)
{
    if (!shape)
        return 0;
    return shape->texture_filename;
}

int set_texture(shape_t *shape, void *texture)
{
    if (!shape || !texture)
        return -1;
    shape->texture = texture;
    return 0;
}

void *get_texture(shape_t *shape)
{
    if (!shape)
        return 0;
    return shape->texture;
}
