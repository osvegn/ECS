/*
 * Filename: ecs_color.h
 * Path: include/utils
 * Created Date: Saturday, September 30th 2023, 6:43:29 pm
 * Author: osvegn
 * 
 * Copyright (c) 2023 ecs
 */

#define uchar unsigned char

typedef struct ecs_color_s {
    uchar r;
    uchar g;
    uchar b;
    uchar a;
} ecs_color_t;

#define RED (ecs_color_t){255, 0, 0, 255}
#define BLUE (ecs_color_t){0, 0, 255, 255}
#define GREEN (ecs_color_t){0, 255, 0, 255}

void copy_color(ecs_color_t *dest, ecs_color_t *src);
void set_color(ecs_color_t *color, uchar r, uchar g, uchar b);
void set_alpha(ecs_color_t *color, uchar alpha);
