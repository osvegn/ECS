/*
 * Filename: world_constructor_tests.c
 * Path: tests/library/ECS
 * Created Date: Monday, January 2nd 2023, 2:38:37 pm
 * Author: osvegn
 *
 * Copyright (c) 2023 ECS
 */

#include <criterion/criterion.h>
#include "world.h"

Test(world_constructor, world_constructor)
{
    world_t world;

    cr_assert_eq(world_constructor(&world, stdout), 0);
    world_destructor(&world);
}

Test(world_destructor, world_destructor_with_entity)
{
    world_t world;
    entity_t entity = {0};
    component_t component = {.type=1};

    entity_constructor(&entity);
    entity_add_component(&entity, &component);
    world.entity_list.emplace_back(&world.entity_list, &entity);
    world_constructor(&world, stdout);
    cr_assert_eq(world.entity_list.size(&world.entity_list), 1);
    world_destructor(&world);
    cr_assert_eq(world.entity_list.size(&world.entity_list), 0);
}

Test(world_destructor, world_destructor_with_resource)
{
    world_t world;
    resource_t resource = {.type=1};

    world_add_resource(&world, &resource);
    world_constructor(&world, stdout);
    cr_assert_eq(world.resource_list.size(&world.resource_list), 1);
    world_destructor(&world);
    cr_assert_eq(world.resource_list.size(&world.resource_list), 0);
}
