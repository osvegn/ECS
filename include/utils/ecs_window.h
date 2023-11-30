/*
 * Filename: ecs_window.h
 * Path: include/utils
 * Created Date: Tuesday, October 3rd 2023, 6:11:06 pm
 * Author: osvegn
 * 
 * Copyright (c) 2023 ECS
 */


typedef struct ecs_window_s {
    unsigned int width;
    unsigned int height;
    unsigned int fps;
    char *name;
} ecs_window_t;

/**
 * Construct a new ecs_window_t structure properly.
 * @param win The window to be construct.
 * @return 0, or -1 if an error occurs.
 */
int window_constructor(ecs_window_t *win);

/**
 * Destruct an existing ecs_window_t structure properly.
 * @param win The window to be destruct.
 */
void window_destructor(ecs_window_t *win);

/**
 * Set the width of a window.
 * @param win The window to be update.
 * @param width The new width of the window.
 */
void set_window_width(ecs_window_t *win, unsigned int width);

/**
 * Get the width of a window.
 * @param win The window to get from.
 * @return The current width of the window.
 */
unsigned int get_window_width(ecs_window_t *win);

/**
 * Set the height of a window.
 * @param win The window to be update.
 * @param height The new height of the window.
 */
void set_window_height(ecs_window_t *win, unsigned int height);

/**
 * Get the height of a window.
 * @param win The window to get from.
 * @return The current height of the window.
 */
unsigned int get_window_height(ecs_window_t *win);

/**
 * Set the fps of a window.
 * @param win The window to be update.
 * @param fps The new fps of the window.
 */
void set_window_fps(ecs_window_t *win, unsigned int fps);

/**
 * Get the fps of a window
 * @param win The window to get from.
 * @return The current fps of the window.
 */
unsigned int get_window_fps(ecs_window_t *win);

/**
 * Set the name of a window.
 * @param win The window to be update.
 * @param name The new name of the window.
 */
void set_window_name(ecs_window_t *win, char *name);

/**
 * Get the name of a window.
 * @param win The window to get from.
 * @return The current name of the window.
 */
char *get_window_name(ecs_window_t *win);

/**
 * Copy a window into another window.
 * @param dest The new window to copy to.
 * @param src The window to copy from.
 */
void copy_window(ecs_window_t *dest, ecs_window_t *src);

void load_window(ecs_window_t *win);
void unload_window(ecs_window_t *win);
