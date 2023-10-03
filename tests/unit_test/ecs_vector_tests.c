/*
 * Filename: ecs_vector_tests.c
 * Path: tests/unit_test
 * Created Date: Tuesday, October 3rd 2023, 3:44:53 pm
 * Author: osvegn
 * 
 * Copyright (c) 2023 ECS
 */

#include "utils/ecs_vector.h"
#include <criterion/criterion.h>

Test(ecs_vector2i, set_vector2i)
{
    ecs_vector2i_t v = {0};

    set_vector2i(&v, 10, 15);
    cr_assert_eq(v.x, 10);
    cr_assert_eq(v.y, 15);
}

Test(ecs_vector2i, add_vector2i)
{
    ecs_vector2i_t v1 = {5, 10};
    ecs_vector2i_t v2 = {15, 20};
    v1 = *add_vector2i(&v1, &v2);
    cr_assert_eq(v1.x, 20);
    cr_assert_eq(v1.y, 30);
}

Test(ecs_vector2i, add_vector2i_value)
{
    ecs_vector2i_t v1 = {5, 10};
    int value = 100;

    v1 = *add_vector2i_value(&v1, value);
    cr_assert_eq(v1.x, 105);
    cr_assert_eq(v1.y, 110);
}

Test(ecs_vector2i, sub_vector2i)
{
    ecs_vector2i_t v1 = {5, 10};
    ecs_vector2i_t v2 = {2, 8};

    v1 = *sub_vector2i(&v1, &v2);
    cr_assert_eq(v1.x, 3);
    cr_assert_eq(v1.y, 2);
}

Test(ecs_vector2i, sub_vector2i_value)
{
    ecs_vector2i_t v1 = {5, 10};
    int value = 8;

    v1 = *sub_vector2i_value(&v1, value);
    cr_assert_eq(v1.x, -3);
    cr_assert_eq(v1.y, 2);
}
