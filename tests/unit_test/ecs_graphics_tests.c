/*
* Filename: ecs_graphics_tests.c
* Path: sources/utils
* Created Date: Saturday, September 30th 2023, 5:01:43 pm
* Author: osvegn
*
* Copyright (c) 2023 ECS
*/

#include <criterion/criterion.h>
#include "utils/ecs_graphics.h"

Test(shape_construction, shape_construction_valid)
{
    shape_t shape;
    int rvalue = shape_constructor(&shape, 4);

    cr_assert_eq(rvalue, 0);
    shape_destructor(&shape);
}

Test(shape_destructor, shape_destructor_valid)
{
    shape_t shape;
    int rvalue = shape_constructor(&shape, 4);

    rvalue = shape_destructor(&shape);
    cr_assert_eq(rvalue, 0);
}

Test(set_shape_color, shape_set_color_valid)
{
    shape_t shape;
    int rvalue = shape_constructor(&shape, 4);
    ecs_color_t color = {10, 50, 168, 255};

    rvalue = set_shape_color(&shape, &color, FILL);
    cr_assert_eq(rvalue, 0);
}

Test(get_shape_color, shape_get_color_valid)
{
    shape_t shape;
    int rvalue = shape_constructor(&shape, 4);
    ecs_color_t color = {10, 50, 156, 255};
    ecs_color_t *new = 0;

    rvalue = set_shape_color(&shape, &color, FILL);
    new = get_shape_color(&shape, FILL);
    cr_assert_eq(new->a, color.a);
    cr_assert_eq(new->r, color.r);
    cr_assert_eq(new->g, color.g);
    cr_assert_eq(new->b, color.b);
    shape_destructor(&shape);
}

Test(set_shape_thichness, set_shape_thickness_valid)
{
    shape_t shape;
    int rvalue = shape_constructor(&shape, 4);
    float value = 10.5f;

    rvalue = set_shape_thickness(&shape, value);
    cr_assert_eq(rvalue, 0);
    shape_destructor(&shape);
}

Test(get_shape_thickness, get_shape_thickness_valid)
{
    shape_t shape;
    int rvalue = shape_constructor(&shape, 4);
    float value = 10.2f;
    float new = 0.0f;

    rvalue = set_shape_thickness(&shape, value);
    new = get_shape_thickness(&shape);
    cr_assert_eq(new, value);
    shape_destructor(&shape);
}
