/*
 * Filename: ecs_event.h
 * Path: include/utils
 * Created Date: Tuesday, October 3rd 2023, 6:19:32 pm
 * Author: osvegn
 * 
 * Copyright (c) 2023 ECS
 */

#include "vector.h"

typedef enum ecs_mouse_e {
    MOUSE_UNDEFINED,
    RIGHT_CLICK,
    LEFT_CLICK,
    MIDDLE_CLICK,
    MOVE_X,
    MOVE_Y,
    WHEEL,
    MOUSE_MAX
} ecs_mouse_t;

typedef enum ecs_keyboard_e {
    KEYBOARD_UNDEFINED,
    KEY_A,
    KEY_B,
    KEY_C,
    KEY_D,
    KEY_E,
    KEY_F,
    KEY_G,
    KEY_H,
    KEY_I,
    KEY_J,
    KEY_K,
    KEY_L,
    KEY_M,
    KEY_N,
    KEY_O,
    KEY_P,
    KEY_Q,
    KEY_R,
    KEY_S,
    KEY_T,
    KEY_U,
    KEY_V,
    KEY_W,
    KEY_X,
    KEY_Y,
    KEY_Z,
    KEY_0,
    KEY_1,
    KEY_2,
    KEY_3,
    KEY_4,
    KEY_5,
    KEY_6,
    KEY_7,
    KEY_8,
    KEY_9,
    KEY_NUMPAD_0,
    KEY_NUMPAD_1,
    KEY_NUMPAD_2,
    KEY_NUMPAD_3,
    KEY_NUMPAD_4,
    KEY_NUMPAD_5,
    KEY_NUMPAD_6,
    KEY_NUMPAD_7,
    KEY_NUMPAD_8,
    KEY_NUMPAD_9,
    KEY_LEFT_CTRL,
    KEY_RIGHT_CTRL,
    KEY_LEFT_SHIFT,
    KEY_RIGHT_SHIFT,
    KEY_TAB,
    KEY_SPACE,
    KEY_ENTER,
    KEY_BACKSPACE,
    KEY_UP_ARROW,
    KEY_DOWN_ARROW,
    KEY_LEFT_ARROW,
    KEY_RIGHT_ARROW,
    KEY_F1,
    KEY_F2,
    KEY_F3,
    KEY_F4,
    KEY_F5,
    KEY_F6,
    KEY_F7,
    KEY_F8,
    KEY_F9,
    KEY_F10,
    KEY_F11,
    KEY_F12,
    KEYBOARD_MAX
} ecs_keyboard_t;

typedef enum ecs_controller_e {
    CONTROLLER_UNDEFINED,
    CONTROLLER_MAX
} ecs_controller_t;

typedef enum ecs_event_type_e {
    EVENT_UNDEFINED,
    EVENT_MOUSE,
    EVENT_KEYBOARD,
    EVENT_CONTROLLER,
    EVENT_MAX
} ecs_event_type_t;

typedef struct ecs_event_s {
    union Input {
        ecs_mouse_t mouse;
        ecs_keyboard_t key;
        ecs_controller_t controller;
    } input;
    ecs_event_type_t type;
    int device_id;
    float value;
} ecs_event_t;

typedef vector_t event_queue;

void event_queue_constructor(void);
void event_queue_destructor(void);
void add_mouse_event(ecs_mouse_t mouse, float value, int device_id);
void add_key_event(ecs_keyboard_t key, float value, int device_id);
void add_controller_event(ecs_controller_t controller, float value, int device_id);

void get_event(ecs_event_t *event);
void event_queue_clear(void);
unsigned int event_queue_size(void);
