/*
 * Filename: ecs_vector.c
 * Path: source/utils
 * Created Date: Saturday, September 30th 2023, 6:38:31 pm
 * Author: osvegn
 * 
 * Copyright (c) 2023 ecs
 */

#include "utils/ecs_vector.h"

/// ecs_vector2i

void set_vector2i(ecs_vector2i_t *vector, int x, int y)
{
    vector->x = x;
    vector->y = y;
}

ecs_vector2i_t *add_vector2i(ecs_vector2i_t *a, ecs_vector2i_t *b)
{
    a->x += b->x;
    a->y += b->y;
    return a;
}

ecs_vector2i_t *add_vector2i_value(ecs_vector2i_t *a, int value)
{
    a->x += value;
    a->y += value;
    return a;
}

ecs_vector2i_t *sub_vector2i(ecs_vector2i_t *a, ecs_vector2i_t *b)
{
    a->x -= b->x;
    a->y -= b->y;
    return a;
}

ecs_vector2i_t *sub_vector2i_value(ecs_vector2i_t *a, int value)
{
    a->x -= value;
    a->y -= value;
    return a;
}

ecs_vector2i_t *mul_vector2i(ecs_vector2i_t *a, ecs_vector2i_t *b)
{
    a->x *= b->x;
    a->y *= b->y;
    return a;
}

ecs_vector2i_t *mul_vector2i_value(ecs_vector2i_t *a, int value)
{
    a->x *= value;
    a->y *= value;
    return a;
}

ecs_vector2i_t *div_vector2i(ecs_vector2i_t *a, ecs_vector2i_t *b)
{
    a->x /= b->x;
    a->y /= b->y;
    return a;
}

ecs_vector2i_t *div_vector2i_value(ecs_vector2i_t *a, int value)
{
    a->x /= value;
    a->y /= value;
    return a;
}

/// ecs_vector3i

void set_vector3i(ecs_vector3i_t *vector, int x, int y, int z)
{
    vector->x = x;
    vector->y = y;
    vector->z = z;
}

ecs_vector3i_t *add_vector3i(ecs_vector3i_t *a, ecs_vector3i_t *b)
{
    a->x += b->x;
    a->y += b->y;
    a->z += b->z;
    return a;
}

ecs_vector3i_t *add_vector3i_value(ecs_vector3i_t *a, int value)
{
    a->x += value;
    a->y += value;
    a->z += value;
    return a;
}

ecs_vector3i_t *sub_vector3i(ecs_vector3i_t *a, ecs_vector3i_t *b)
{
    a->x -= b->x;
    a->y -= b->y;
    a->z -= b->z;
    return a;
}

ecs_vector3i_t *sub_vector3i_value(ecs_vector3i_t *a, int value)
{
    a->x -= value;
    a->y -= value;
    a->z -= value;
    return a;
}

ecs_vector3i_t *mul_vector3i(ecs_vector3i_t *a, ecs_vector3i_t *b)
{
    a->x *= b->x;
    a->y *= b->y;
    a->z *= b->z;
    return a;
}

ecs_vector3i_t *mul_vector3i_value(ecs_vector3i_t *a, int value)
{
    a->x *= value;
    a->y *= value;
    a->z *= value;
    return a;
}

ecs_vector3i_t *div_vector3i(ecs_vector3i_t *a, ecs_vector3i_t *b)
{
    a->x /= b->x;
    a->y /= b->y;
    a->z /= b->z;
    return a;
}

ecs_vector3i_t *div_vector3i_value(ecs_vector3i_t *a, int value)
{
    a->x /= value;
    a->y /= value;
    a->z /= value;
    return a;
}

/// ecs_vector2f

void set_vector2f(ecs_vector2f_t *vector, float x, float y)
{
    vector->x = x;
    vector->y = y;
}

ecs_vector2f_t *add_vector2f(ecs_vector2f_t *a, ecs_vector2f_t *b)
{
    a->x += b->x;
    a->y += b->y;
    return a;
}

ecs_vector2f_t *add_vector2f_value(ecs_vector2f_t *a, float value)
{
    a->x += value;
    a->y += value;
    return a;
}

ecs_vector2f_t *sub_vector2f(ecs_vector2f_t *a, ecs_vector2f_t *b)
{
    a->x -= b->x;
    a->y -= b->y;
    return a;
}

ecs_vector2f_t *sub_vector2f_value(ecs_vector2f_t *a, float value)
{
    a->x -= value;
    a->y -= value;
    return a;
}

ecs_vector2f_t *mul_vector2f(ecs_vector2f_t *a, ecs_vector2f_t *b)
{
    a->x *= b->x;
    a->y *= b->y;
    return a;
}

ecs_vector2f_t *mul_vector2f_value(ecs_vector2f_t *a, float value)
{
    a->x *= value;
    a->y *= value;
    return a;
}

ecs_vector2f_t *div_vector2f(ecs_vector2f_t *a, ecs_vector2f_t *b)
{
    a->x /= b->x;
    a->y /= b->y;
    return a;
}

ecs_vector2f_t *div_vector2f_value(ecs_vector2f_t *a, float value)
{
    a->x /= value;
    a->y /= value;
    return a;
}

/// ecs_vector3f

void set_vector3f(ecs_vector3f_t *vector, float x, float y, float z)
{
    vector->x = x;
    vector->y = y;
    vector->z = z;
}

ecs_vector3f_t *add_vector3f(ecs_vector3f_t *a, ecs_vector3f_t *b)
{
    a->x += b->x;
    a->y += b->y;
    a->z += b->z;
    return a;
}

ecs_vector3f_t *add_vector3f_value(ecs_vector3f_t *a, float value)
{
    a->x += value;
    a->y += value;
    a->z += value;
    return a;
}

ecs_vector3f_t *sub_vector3f(ecs_vector3f_t *a, ecs_vector3f_t *b)
{
    a->x -= b->x;
    a->y -= b->y;
    a->z -= b->z;
    return a;
}

ecs_vector3f_t *sub_vector3f_value(ecs_vector3f_t *a, float value)
{
    a->x -= value;
    a->y -= value;
    a->z -= value;
    return a;
}

ecs_vector3f_t *mul_vector3f(ecs_vector3f_t *a, ecs_vector3f_t *b)
{
    a->x *= b->x;
    a->y *= b->y;
    a->z *= b->z;
    return a;
}

ecs_vector3f_t *mul_vector3f_value(ecs_vector3f_t *a, float value)
{
    a->x *= value;
    a->y *= value;
    a->z *= value;
    return a;
}

ecs_vector3f_t *div_vector3f(ecs_vector3f_t *a, ecs_vector3f_t *b)
{
    a->x /= b->x;
    a->y /= b->y;
    a->z /= b->z;
    return a;
}

ecs_vector3f_t *div_vector3f_value(ecs_vector3f_t *a, float value)
{
    a->x /= value;
    a->y /= value;
    a->z /= value;
    return a;
}
