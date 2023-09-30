/*
 * Filename: /home/osvegn/Documents/Repositories/ECS/include/ecs_vector.h
 * Path: /home/osvegn/Documents/Repositories/ECS/include
 * Created Date: Saturday, September 30th 2023, 6:20:54 pm
 * Author: osvegn
 * 
 * Copyright (c) 2023 ecs
 */

typedef struct ecs_vector2i_s {
    int x;
    int y;
} ecs_vector2i_t;

void set_vector2i(ecs_vector2i_t *vector, int x, int y);
ecs_vector2i_t *add_vector2i(ecs_vector2i_t *a, ecs_vector2i_t *b);
ecs_vector2i_t *add_vector2i_value(ecs_vector2i_t *a, int value);
ecs_vector2i_t *sub_vector2i(ecs_vector2i_t *a, ecs_vector2i_t *b);
ecs_vector2i_t *sub_vector2i_value(ecs_vector2i_t *a, int value);
ecs_vector2i_t *mul_vector2i(ecs_vector2i_t *a, ecs_vector2i_t *b);
ecs_vector2i_t *mul_vector2i_value(ecs_vector2i_t *a, int value);
ecs_vector2i_t *div_vector2i(ecs_vector2i_t *a, ecs_vector2i_t *b);
ecs_vector2i_t *div_vector2i_value(ecs_vector2i_t *a, int value);

typedef struct ecs_vector3i_s {
    int x;
    int y;
    int z;
} ecs_vector3i_t;


void set_vector3i(ecs_vector3i_t *vector, int x, int y, int z);
ecs_vector3i_t *add_vector3i(ecs_vector3i_t *a, ecs_vector3i_t *b);
ecs_vector3i_t *add_vector3i_value(ecs_vector3i_t *a, int value);
ecs_vector3i_t *sub_vector3i(ecs_vector3i_t *a, ecs_vector3i_t *b);
ecs_vector3i_t *sub_vector3i_value(ecs_vector3i_t *a, int value);
ecs_vector3i_t *mul_vector3i(ecs_vector3i_t *a, ecs_vector3i_t *b);
ecs_vector3i_t *mul_vector3i_value(ecs_vector3i_t *a, int value);
ecs_vector3i_t *div_vector3i(ecs_vector3i_t *a, ecs_vector3i_t *b);
ecs_vector3i_t *div_vector3i_value(ecs_vector3i_t *a, int value);

typedef struct ecs_vector2f_s {
    float x;
    float y;
} ecs_vector2f_t;

void set_vector2f(ecs_vector2f_t *vector, float x, float y);
ecs_vector2f_t *add_vector2f(ecs_vector2f_t *a, ecs_vector2f_t *b);
ecs_vector2f_t *add_vector2f_value(ecs_vector2f_t *a, float value);
ecs_vector2f_t *sub_vector2f(ecs_vector2f_t *a, ecs_vector2f_t *b);
ecs_vector2f_t *sub_vector2f_value(ecs_vector2f_t *a, float value);
ecs_vector2f_t *mul_vector2f(ecs_vector2f_t *a, ecs_vector2f_t *b);
ecs_vector2f_t *mul_vector2f_value(ecs_vector2f_t *a, float value);
ecs_vector2f_t *div_vector2f(ecs_vector2f_t *a, ecs_vector2f_t *b);
ecs_vector2f_t *div_vector2f_value(ecs_vector2f_t *a, float value);

typedef struct ecs_vector3f_s {
    float x;
    float y;
    float z;
} ecs_vector3f_t;

void set_vector3f(ecs_vector3f_t *vector, float x, float y, float z);
ecs_vector3f_t *add_vector3f(ecs_vector3f_t *a, ecs_vector3f_t *b);
ecs_vector3f_t *add_vector3f_value(ecs_vector3f_t *a, float value);
ecs_vector3f_t *sub_vector3f(ecs_vector3f_t *a, ecs_vector3f_t *b);
ecs_vector3f_t *sub_vector3f_value(ecs_vector3f_t *a, float value);
ecs_vector3f_t *mul_vector3f(ecs_vector3f_t *a, ecs_vector3f_t *b);
ecs_vector3f_t *mul_vector3f_value(ecs_vector3f_t *a, float value);
ecs_vector3f_t *div_vector3f(ecs_vector3f_t *a, ecs_vector3f_t *b);
ecs_vector3f_t *div_vector3f_value(ecs_vector3f_t *a, float value);