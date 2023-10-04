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

Test(ecs_vector2i, mul_vector2i)
{
    ecs_vector2i_t v1 = {5, 10};
    ecs_vector2i_t v2 = {2, 8};

    v1 = *mul_vector2i(&v1, &v2);
    cr_assert_eq(v1.x, 10);
    cr_assert_eq(v1.y, 80);
}

Test(ecs_vector2i, mul_vector2i_value)
{
    ecs_vector2i_t v1 = {5, 10};
    int value = 8;

    v1 = *mul_vector2i_value(&v1, value);
    cr_assert_eq(v1.x, 40);
    cr_assert_eq(v1.y, 80);
}

Test(ecs_vector2i, div_vector2i)
{
    ecs_vector2i_t v1 = {5, 10};
    ecs_vector2i_t v2 = {2, 8};

    v1 = *div_vector2i(&v1, &v2);
    cr_assert_eq(v1.x, 2);
    cr_assert_eq(v1.y, 1);
}

Test(ecs_vector2i, div_vector2i_value)
{
    ecs_vector2i_t v1 = {5, 10};
    int value = 8;

    v1 = *div_vector2i_value(&v1, value);
    cr_assert_eq(v1.x, 0);
    cr_assert_eq(v1.y, 1);
}

Test(ecs_vector3i_t, set_vector3i)
{
    ecs_vector3i_t v = {0};

    set_vector3i(&v, 10, 15, 20);
    cr_assert_eq(v.x, 10);
    cr_assert_eq(v.y, 15);
    cr_assert_eq(v.z, 20);
}

Test(ecs_vector3i_t, add_vector3i)
{
    ecs_vector3i_t v1 = {5, 10, 15};
    ecs_vector3i_t v2 = {15, 20, 25};

    v1 = *add_vector3i(&v1, &v2);
    cr_assert_eq(v1.x, 20);
    cr_assert_eq(v1.y, 30);
    cr_assert_eq(v1.z, 40);
}

Test(ecs_vector3i_t, add_vector3i_value)
{
    ecs_vector3i_t v1 = {5, 10, 15};
    int value = 100;

    v1 = *add_vector3i_value(&v1, value);
    cr_assert_eq(v1.x, 105);
    cr_assert_eq(v1.y, 110);
    cr_assert_eq(v1.z, 115);
}

Test(ecs_vector3i_t, sub_vector3i)
{
    ecs_vector3i_t v1 = {5, 10, 15};
    ecs_vector3i_t v2 = {2, 8, 12};

    v1 = *sub_vector3i(&v1, &v2);
    cr_assert_eq(v1.x, 3);
    cr_assert_eq(v1.y, 2);
    cr_assert_eq(v1.z, 3);
}

Test(ecs_vector3i_t, sub_vector3i_value)
{
    ecs_vector3i_t v1 = {5, 10, 15};
    int value = 8;

    v1 = *sub_vector3i_value(&v1, value);
    cr_assert_eq(v1.x, -3);
    cr_assert_eq(v1.y, 2);
    cr_assert_eq(v1.z, 7);
}

Test(ecs_vector3i_t, mul_vector3i)
{
    ecs_vector3i_t v1 = {5, 10, 15};
    ecs_vector3i_t v2 = {2, 8, 12};

    v1 = *mul_vector3i(&v1, &v2);
    cr_assert_eq(v1.x, 10);
    cr_assert_eq(v1.y, 80);
    cr_assert_eq(v1.z, 180);
}

Test(ecs_vector3i_t, mul_vector3i_value)
{
    ecs_vector3i_t v1 = {5, 10, 15};
    int value = 8;

    v1 = *mul_vector3i_value(&v1, value);
    cr_assert_eq(v1.x, 40);
    cr_assert_eq(v1.y, 80);
    cr_assert_eq(v1.z, 120);
}

Test(ecs_vector3i_t, div_vector3i)
{
    ecs_vector3i_t v1 = {5, 10, 15};
    ecs_vector3i_t v2 = {2, 8, 12};

    v1 = *div_vector3i(&v1, &v2);
    cr_assert_eq(v1.x, 2);
    cr_assert_eq(v1.y, 1);
    cr_assert_eq(v1.z, 1);
}

Test(ecs_vector3i_t, div_vector3i_value)
{
    ecs_vector3i_t v1 = {5, 10, 15};
    int value = 8;

    v1 = *div_vector3i_value(&v1, value);
    cr_assert_eq(v1.x, 0);
    cr_assert_eq(v1.y, 1);
    cr_assert_eq(v1.z, 1);
}

Test(ecs_vector2f_t, set_vector2f)
{
    ecs_vector2f_t v = {0};

    set_vector2f(&v, 10.5, 15.5);
    cr_assert_eq(v.x, 10.5);
    cr_assert_eq(v.y, 15.5);
}

Test(ecs_vector2f_t, add_vector2f)
{
    ecs_vector2f_t v1 = {5.5, 10.5};
    ecs_vector2f_t v2 = {15.5, 20.5};

    v1 = *add_vector2f(&v1, &v2);
    cr_assert_eq(v1.x, 21);
    cr_assert_eq(v1.y, 31);
}

Test(ecs_vector2f_t, add_vector2f_value)
{
    ecs_vector2f_t v1 = {5.5, 10.5};
    float value = 100.5;

    v1 = *add_vector2f_value(&v1, value);
    cr_assert_eq(v1.x, 106);
    cr_assert_eq(v1.y, 111);
}

Test(ecs_vector2f_t, sub_vector2f)
{
    ecs_vector2f_t v1 = {5.5, 10.5};
    ecs_vector2f_t v2 = {2.5, 8.5};

    v1 = *sub_vector2f(&v1, &v2);
    cr_assert_eq(v1.x, 3);
    cr_assert_eq(v1.y, 2);
}

Test(ecs_vector2f_t, sub_vector2f_value)
{
    ecs_vector2f_t v1 = {5.5, 10.5};
    float value = 8.5;

    v1 = *sub_vector2f_value(&v1, value);
    cr_assert_eq(v1.x, -3);
    cr_assert_eq(v1.y, 2);
}

Test(ecs_vector2f_t, mul_vector2f)
{
    ecs_vector2f_t v1 = {5.5, 10.5};
    ecs_vector2f_t v2 = {2.5, 8.5};

    v1 = *mul_vector2f(&v1, &v2);
    cr_assert_eq(v1.x, 13.75);
    cr_assert_eq(v1.y, 89.25);
}

Test(ecs_vector2f_t, mul_vector2f_value)
{
    ecs_vector2f_t v1 = {5.5, 10.5};
    float value = 8.5;

    v1 = *mul_vector2f_value(&v1, value);
    cr_assert_eq(v1.x, 46.75);
    cr_assert_eq(v1.y, 89.25);
}

Test(ecs_vector2f_t, div_vector2f)
{
    ecs_vector2f_t v1 = {5.5, 10.5};
    ecs_vector2f_t v2 = {2.5, 2.0};

    v1 = *div_vector2f(&v1, &v2);
    cr_assert_eq(v1.x, 2.2);
    cr_assert_eq(v1.y, 5.25);
}

Test(ecs_vector2f_t, div_vector2f_value)
{
    ecs_vector2f_t v1 = {5.5, 10.5};
    float value = 4;

    v1 = *div_vector2f_value(&v1, value);
    cr_assert_eq(v1.x, 1.375);
    cr_assert_eq(v1.y, 2.625);
}

Test(ecs_vector3f_t, set_vector3f)
{
    ecs_vector3f_t v = {0};

    set_vector3f(&v, 10.5, 15.5, 20.5);
    cr_assert_eq(v.x, 10.5);
    cr_assert_eq(v.y, 15.5);
    cr_assert_eq(v.z, 20.5);
}

Test(ecs_vector3f_t, add_vector3f)
{
    ecs_vector3f_t v1 = {5.5, 10.5, 15.5};
    ecs_vector3f_t v2 = {15.5, 20.5, 25.5};

    v1 = *add_vector3f(&v1, &v2);
    cr_assert_eq(v1.x, 21);
    cr_assert_eq(v1.y, 31);
    cr_assert_eq(v1.z, 41);
}

Test(ecs_vector3f_t, add_vector3f_value)
{
    ecs_vector3f_t v1 = {5.5, 10.5, 15.5};
    float value = 100.5;

    v1 = *add_vector3f_value(&v1, value);
    cr_assert_eq(v1.x, 106);
    cr_assert_eq(v1.y, 111);
    cr_assert_eq(v1.z, 116);
}

Test(ecs_vector3f_t, sub_vector3f)
{
    ecs_vector3f_t v1 = {5.5, 10.5, 15.5};
    ecs_vector3f_t v2 = {2.5, 8.5, 12.5};

    v1 = *sub_vector3f(&v1, &v2);
    cr_assert_eq(v1.x, 3);
    cr_assert_eq(v1.y, 2);
    cr_assert_eq(v1.z, 3);
}

Test(ecs_vector3f_t, sub_vector3f_value)
{
    ecs_vector3f_t v1 = {5.5, 10.5, 15.5};
    float value = 8.5;

    v1 = *sub_vector3f_value(&v1, value);
    cr_assert_eq(v1.x, -3);
    cr_assert_eq(v1.y, 2);
    cr_assert_eq(v1.z, 7);
}

Test(ecs_vector3f_t, mul_vector3f)
{
    ecs_vector3f_t v1 = {5.5, 10.5, 15.5};
    ecs_vector3f_t v2 = {2.5, 8.5, 12.5};

    v1 = *mul_vector3f(&v1, &v2);
    cr_assert_eq(v1.x, 13.75);
    cr_assert_eq(v1.y, 89.25);
    cr_assert_eq(v1.z, 193.75);
}

Test(ecs_vector3f_t, mul_vector3f_value)
{
    ecs_vector3f_t v1 = {5.5, 10.5, 15.5};
    float value = 8.5;

    v1 = *mul_vector3f_value(&v1, value);
    cr_assert_eq(v1.x, 46.75);
    cr_assert_eq(v1.y, 89.25);
    cr_assert_eq(v1.z, 131.75);
}

Test(ecs_vector3f_t, div_vector3f)
{
    ecs_vector3f_t v1 = {5.5, 10.5, 15.5};
    ecs_vector3f_t v2 = {2.5, 2, 12.5};

    // 5.5 / 2.5 = 2.2
    v1 = *div_vector3f(&v1, &v2);
    cr_assert_eq(v1.x, 2.2);
    cr_assert_eq(v1.y, 5.25);
    cr_assert_eq(v1.z, 1.24);
}

Test(ecs_vector3f_t, div_vector3f_value)
{
    ecs_vector3f_t v1 = {5.5, 10.5, 15.5};
    float value = 4;

    v1 = *div_vector3f_value(&v1, value);
    cr_assert_eq(v1.x, 1.375);
    cr_assert_eq(v1.y, 2.625);
    cr_assert_eq(v1.z, 3.875);
}
