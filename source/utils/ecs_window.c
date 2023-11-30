/*
* Filename: ecs_window.c
* Path: tests/unit_test
* Created Date: Thursday, November 30th 2023, 5:39 pm
* Author: osvegn
*
* Copyright (c) 2023 ECS
 */

#include "utils/ecs_window.h"
#include <stdlib.h>
#include <string.h>

static void remove_name(ecs_window_t *win)
{
    if (win->name)
        free(win->name);
    win->name = NULL;
}

int window_constructor(ecs_window_t *win)
{
    win->fps = 60;
    win->height = 300;
    win->width = 300;
    win->name = strdup("Untitled");
    return win->name != NULL;
}

void window_destructor(ecs_window_t *win)
{
    remove_name(win);
}

void set_window_width(ecs_window_t *win, unsigned int width)
{
    win->width = width;
}

unsigned int get_window_width(ecs_window_t *win)
{
    return win->width;
}

void set_window_height(ecs_window_t *win, unsigned int height)
{
    win->height = height;
}

unsigned int get_window_height(ecs_window_t *win)
{
    return win->height;
}

void set_window_fps(ecs_window_t *win, unsigned int fps)
{
    win->fps = fps;
}

unsigned int get_window_fps(ecs_window_t *win)
{
    return win->fps;
}

void set_window_name(ecs_window_t *win, char *name)
{
    remove_name(win);
    win->name = strdup(name);
}

char *get_window_name(ecs_window_t *win)
{
    return win->name;
}

void copy_window(ecs_window_t *dest, ecs_window_t *src)
{
    window_constructor(dest);
    set_window_width(dest, get_window_width(src));
    set_window_height(dest, get_window_height(src));
    set_window_fps(dest, get_window_fps(src));
    set_window_name(dest, get_window_name(src));
}
