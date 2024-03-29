/*
* Filename: ecs_event_tests.c
* Path: tests/unit_test
* Created Date: Thursday, November 30th 2023, 5:39 pm
* Author: osvegn
*
* Copyright (c) 2023 ECS
*/

#include <criterion/criterion.h>
#include "utils/ecs_event.h"

Test(ecs_event_constructor, ecs_event_constructor)
{
    event_queue_constructor();
    cr_assert_eq(event_queue_size(), 0);
    event_queue_destructor();
}

Test(ecs_event_constructor, ecs_event_constructor_with_one_element)
{
    event_queue_constructor();
    add_mouse_event(RIGHT_CLICK, 1, 0);
    cr_assert_eq(event_queue_size(), 1);
    event_queue_destructor();
}

Test(ecs_event_constructor, ecs_event_constructor_with_two_elements)
{
    event_queue_constructor();
    add_mouse_event(RIGHT_CLICK, 1, 0);
    add_mouse_event(LEFT_CLICK, 1, 0);
    cr_assert_eq(event_queue_size(), 2);
    event_queue_destructor();
}

Test(ecs_event_add_mouse_event, ecs_event_add_mouse_event)
{
    event_queue_constructor();
    add_mouse_event(RIGHT_CLICK, 1, 0);
    cr_assert_eq(event_queue_size(), 1);
    event_queue_destructor();
}

Test(ecs_event_add_mouse_event, ecs_event_add_mouse_event_with_two_elements)
{
    event_queue_constructor();
    add_mouse_event(RIGHT_CLICK, 1, 0);
    add_mouse_event(LEFT_CLICK, 1, 0);
    cr_assert_eq(event_queue_size(), 2);
    event_queue_destructor();
}

Test(ecs_event_add_key_event, ecs_event_add_key_event)
{
    event_queue_constructor();
    add_key_event(KEY_0, 1, 0);
    cr_assert_eq(event_queue_size(), 1);
    event_queue_destructor();
}

Test(ecs_event_add_key_event, ecs_event_add_key_event_with_two_elements)
{
    event_queue_constructor();
    add_key_event(KEY_0, 1, 0);
    add_key_event(KEY_1, 1, 0);
    cr_assert_eq(event_queue_size(), 2);
    event_queue_destructor();
}

Test(ecs_event_add_key_and_mouse_event, ecs_event_add_key_and_mouse_event)
{
    event_queue_constructor();
    add_key_event(KEY_0, 1, 0);
    add_mouse_event(RIGHT_CLICK, 1, 0);
    cr_assert_eq(event_queue_size(), 2);
    event_queue_destructor();
}

Test(ecs_event_add_key_and_mouse_event, ecs_event_add_key_and_mouse_event_with_two_elements)
{
    event_queue_constructor();
    add_key_event(KEY_0, 1, 0);
    add_mouse_event(RIGHT_CLICK, 1, 0);
    add_key_event(KEY_1, 1, 0);
    add_mouse_event(LEFT_CLICK, 1, 0);
    cr_assert_eq(event_queue_size(), 4);
    event_queue_destructor();
}

Test(ecs_event_get_event, ecs_event_get_event)
{
    ecs_event_t event;

    event_queue_constructor();
    add_key_event(KEY_0, 1, 0);
    add_mouse_event(RIGHT_CLICK, 1, 0);
    cr_assert_eq(event_queue_size(), 2);
    get_event(&event);
    cr_assert_eq(event.input.key, KEY_0);
    cr_assert_eq(event.value, 1);
    cr_assert_eq(event.device_id, 0);
    cr_assert_eq(event.type, EVENT_KEYBOARD);
    cr_assert_eq(event_queue_size(), 1);
    get_event(&event);
    cr_assert_eq(event.input.mouse, RIGHT_CLICK);
    cr_assert_eq(event.type, EVENT_MOUSE);
    cr_assert_eq(event.value, 1);
    cr_assert_eq(event.device_id, 0);
    cr_assert_eq(event_queue_size(), 0);
    event_queue_destructor();
}

Test(ecs_event_clear_queue, ecs_event_clear_queue)
{
    event_queue_constructor();
    add_key_event(KEY_0, 1, 0);
    add_mouse_event(RIGHT_CLICK, 1, 0);
    cr_assert_eq(event_queue_size(), 2);
    event_queue_clear();
    cr_assert_eq(event_queue_size(), 0);
    event_queue_destructor();
}

Test(ecs_event_clear_queue, ecs_event_clear_empty_queue)
{
    event_queue_constructor();
    cr_assert_eq(event_queue_size(), 0);
    event_queue_clear();
    cr_assert_eq(event_queue_size(), 0);
    event_queue_destructor();
}
