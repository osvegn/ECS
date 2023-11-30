/*
* Filename: ecs_event.c
* Path: source/utils
* Created Date: Thursday, November 30th 2023, 5:39 pm
* Author: osvegn
*
* Copyright (c) 2023 ECS
 */

#include "utils/ecs_event.h"

static event_queue queue = {0};

void event_queue_constructor(void)
{
    vector_constructor(&queue, sizeof(event_t), 10);
}

void event_queue_destructor()
{
    queue.destructor(&queue);
}

void add_mouse_event(ecs_mouse_t mouse, float value, int device_id)
{
    event_t e = {
        .controller=CONTROLLER_UNDEFINED,
        .device_id=device_id,
        .key=KEYBOARD_UNDEFINED,
        .mouse=mouse,
        .value=value
    };
    queue.emplace_back(&queue, &e);

}

void add_key_event(ecs_keyboard_t key, float value, int device_id)
{
    event_t e = {
        .controller=CONTROLLER_UNDEFINED,
        .device_id=device_id,
        .key=key,
        .mouse=MOUSE_UNDEFINED,
        .value=value
    };
    queue.emplace_back(&queue, &e);
}

void add_controller_event(ecs_controller_t controller, float value, int device_id)
{
    event_t e = {
        .controller=controller,
        .device_id=device_id,
        .key=KEYBOARD_UNDEFINED,
        .mouse=MOUSE_UNDEFINED,
        .value=value,
    };
    queue.emplace_back(&queue, &e);
}

void get_event(event_t *event)
{
    (*event) = *(event_t *)queue.at(&queue, 0);
    queue.erase(&queue, 0);
}

void event_queue_clear(void)
{
    queue.clear(&queue);
}

unsigned int event_queue_size(void)
{
    return queue.size(&queue);
}