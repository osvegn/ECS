/*
 * Filename: component_destructor_tests.c
 * Path: tests/library/ECS
 * Created Date: Sunday, January 15th 2023, 3:59:16 pm
 * Author: osvegn
 *
 * Copyright (c) 2023 ECS
 */

#include <criterion/criterion.h>
#include "component.h"

Test(component_destructor, test_component_destructor)
{
    component_t component = {0};

    component.type = 1;
    component.data = malloc(sizeof(char) * 2);
    ((char *)component.data)[0] = 'i';
    ((char *)component.data)[1] = '\0';
    cr_assert_neq(component.data, 0);
    component_destructor(&component);
    cr_assert_eq(component.data, 0);
}

Test(component_destructor, test_component_destructor_empty_data)
{
    component_t component = {0};

    component.type = 1;
    cr_assert_eq(component.data, 0);
    component_destructor(&component);
    cr_assert_eq(component.data, 0);
}
