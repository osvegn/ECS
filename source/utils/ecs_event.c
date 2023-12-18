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
    vector_constructor(&queue, sizeof(ecs_event_t), 10);
}

void event_queue_destructor()
{
    queue.destructor(&queue);
}

void add_mouse_event(ecs_mouse_t mouse, float value, int device_id)
{
    ecs_event_t e = {
        .device_id=device_id,
        .input.mouse=mouse,
        .value=value,
        .type=EVENT_MOUSE
    };
    queue.emplace_back(&queue, &e);

}

void add_key_event(ecs_keyboard_t key, float value, int device_id)
{
    ecs_event_t e = {
        .device_id=device_id,
        .input.key=key,
        .value=value,
        .type=EVENT_KEYBOARD
    };
    queue.emplace_back(&queue, &e);
}

void add_controller_event(ecs_controller_t controller, float value, int device_id)
{
    ecs_event_t e = {
        .input.controller=controller,
        .device_id=device_id,
        .value=value,
        .type=EVENT_CONTROLLER
    };
    queue.emplace_back(&queue, &e);
}

void get_event(ecs_event_t *event)
{
    (*event) = *(ecs_event_t *)queue.at(&queue, 0);
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
