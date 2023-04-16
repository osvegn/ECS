/*
 * Filename: /workspaces/our_rpg/tests/library/ECS/entity_component_tests.c
 * Path: /workspaces/our_rpg/tests/library/ECS
 * Created Date: Sunday, January 15th 2023, 3:59:16 pm
 * Author: osvegn
 * 
 * Copyright (c) 2023 our_rpg
 */

#include <criterion/criterion.h>
#include "entity.h"
#include "component.h"

Test(entity_component, test_entity_constructor)
{
    entity_t entity;

    cr_assert_eq(entity_constructor(&entity), 0);
}

Test(entity_component, test_entity_entity_add_component_success)
{
    entity_t entity;
    component_t component = {.type = 0, .data = 0};

    entity_constructor(&entity);
    cr_assert_eq(entity_add_component(&entity, &component), 0);
}

Test(entity_component, test_entity_entity_add_component_failure)
{
    entity_t entity;
    component_t component = {.type = 0, .data = 0};

    entity_constructor(&entity);
    entity_add_component(&entity, &component);
    cr_assert_eq(entity_add_component(&entity, &component), -1);
}

Test(entity_component, test_entity_entity_remove_component_success)
{
    entity_t entity;
    component_t component = {.type = 0, .data = 0};

    entity_constructor(&entity);
    entity_add_component(&entity, &component);
    cr_assert_eq(entity_remove_component(&entity, &component), 0);
}

Test(entity_component, test_entity_entity_remove_component_failure)
{
    entity_t entity;
    component_t component = {.type = 0, .data = 0};

    entity_constructor(&entity);
    entity_add_component(&entity, &component);
    entity_remove_component(&entity, &component);
    cr_assert_eq(entity_remove_component(&entity, &component), -1);
}

Test(entity_contains_component, test_entity_entity_contains_component_success)
{
    entity_t entity;
    component_t component = {.type = 0, .data = 0};

    entity_constructor(&entity);
    entity_add_component(&entity, &component);
    cr_assert_eq(entity_contains_component(&entity, &component), true);
}

Test(entity_contains_component, test_entity_entity_contains_component_failure)
{
    entity_t entity;
    component_t component;

    entity_constructor(&entity);
    entity_add_component(&entity, &component);
    component.type = 1;
    cr_assert_eq(entity_contains_component(&entity, &component), false);
}
