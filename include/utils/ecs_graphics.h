/*
 * Filename: ecs_graphics.c
 * Path: includes/utils
 * Created Date: Saturday, September 30th 2023, 4:43:40 pm
 * Author: osvegn
 * 
 * Copyright (c) 2023 ecs
 */

#include "vector.h"
#include "ecs_color.h"
#include "ecs_vector.h"

typedef enum shape_color_e {
    FILL,
    OUTLINE,
    MAX
} shape_color_t;

typedef struct shape_s {
    vector_t points;
    ecs_color_t color[MAX];
    float thickness;
    bool is_filled;
} shape_t;

int shape_constructor(shape_t *shape, int point_number);
int shape_destructor(shape_t *shape);

int set_color(shape_t *shape, ecs_color_t *color, shape_color_t type);
ecs_color_t *get_color(shape_t *shape, shape_color_t type);

int set_thickness(shape_t *shape, float value);
float get_thickness(shape_t *shape);

int set_is_filled(shape_t *shape, bool value);
bool get_is_filled(shape_t *shape);

int set_points(shape_t *shape, vector_t *points);
int set_point(shape_t *shape, ecs_vector2f_t *point, int index);

void draw_shape(shape_t *shape);
