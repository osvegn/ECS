/*
 * Filename: ecs_graphics.c
 * Path: includes/utils
 * Created Date: Saturday, September 30th 2023, 4:43:40 pm
 * Author: osvegn
 * 
 * Copyright (c) 2023 ECS
 */

#include "vector.h"
#include "utils/ecs_color.h"
#include "utils/ecs_vector.h"

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
    void *texture;
    char *texture_filename;
} shape_t;

int shape_constructor(shape_t *shape, int point_number);
int shape_destructor(shape_t *shape);

int set_shape_color(shape_t *shape, ecs_color_t *color, shape_color_t type);
ecs_color_t *get_shape_color(shape_t *shape, shape_color_t type);

int set_shape_thickness(shape_t *shape, float value);
float get_shape_thickness(shape_t *shape);

int set_shape_is_filled(shape_t *shape, bool value);
bool get_shape_is_filled(shape_t *shape);

int set_shape_points(shape_t *shape, vector_t *points);
int set_shape_point(shape_t *shape, ecs_vector2f_t *point, int index);

int set_texture_filename(shape_t *shape, char *filename);
char *get_texture_filename(shape_t *shape);

int set_texture(shape_t *shape, void *texture);
void *get_texture(shape_t *shape);

int load_texture(shape_t *shape, char *filename);
int draw_shape(shape_t *shape);
