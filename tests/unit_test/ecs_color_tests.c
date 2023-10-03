/*
 * Filename: ecs_color_tests.c
 * Path: tests/unit_test
 * Created Date: Tuesday, October 3rd 2023, 3:34:04 pm
 * Author: osvegn
 * 
 * Copyright (c) 2023 ecs
 */

#include "utils/ecs_color.h"
#include <criterion/criterion.h>

Test(copy_color, copy_red_color)
{
    ecs_color_t c = RED;
    ecs_color_t new = {};

    copy_color(&new, &c);
    cr_assert_eq(new.r, 255);
}

Test(set_color, set_blue_color)
{
    ecs_color_t c = {0};

    set_color(&c, 0, 0, 255);
    cr_assert_eq(c.b, 255);
}

Test(set_alpha, set_alpha)
{
    ecs_color_t c = {0};

    set_alpha(&c, 100);
    cr_assert_eq(c.a, 100);
}
