/*
 * Filename: /workspaces/our_rpg/tests/library/ECS/world_resource_tests.c
 * Path: /workspaces/our_rpg/tests/library/ECS
 * Created Date: Sunday, January 15th 2023, 3:59:16 pm
 * Author: osvegn
 * 
 * Copyright (c) 2023 our_rpg
 */

#include <criterion/criterion.h>
#include "world.h"
#include "world_resource.h"

Test(world_world_add_resource, world_world_add_resource)
{
    world_t world;
    resource_t resource;

    resource.type = 0;
    vector_constructor(&world.resource_list, sizeof(int), 0);
    cr_assert_eq(world_add_resource(&world, &resource), 0);
    cr_assert_eq(world.resource_list.size(&world.resource_list), 1);
}

Test(world_world_add_resource, world_world_add_resource_failure)
{
    world_t world;
    resource_t resource;

    resource.type = 0;
    vector_constructor(&world.resource_list, sizeof(int), 0);
    cr_assert_eq(world_add_resource(&world, &resource), 0);
    cr_assert_eq(world_add_resource(&world, &resource), -1);
    cr_assert_eq(world.resource_list.size(&world.resource_list), 1);
}

Test(world_world_add_resource, world_world_add_resource_success_with_two_elements)
{
    world_t world;
    resource_t resource;

    resource.type = 0;
    vector_constructor(&world.resource_list, sizeof(int), 0);
    cr_assert_eq(world_add_resource(&world, &resource), 0);
    resource.type = 1;
    cr_assert_eq(world_add_resource(&world, &resource), 0);
    cr_assert_eq(world.resource_list.size(&world.resource_list), 2);
}

Test(world_world_remove_resource, world_world_remove_resource)
{
    world_t world;
    resource_t resource;

    resource.type = 0;
    vector_constructor(&world.resource_list, sizeof(int), 0);
    cr_assert_eq(world_add_resource(&world, &resource), 0);
    resource.type = 1;
    cr_assert_eq(world_add_resource(&world, &resource), 0);
    cr_assert_eq(world_remove_resource(&world, &resource), 0);
    cr_assert_eq(world.resource_list.size(&world.resource_list), 1);
}

Test(world_world_remove_resource, world_world_remove_resource_failure)
{
    world_t world;
    resource_t resource;

    resource.type = 0;
    vector_constructor(&world.resource_list, sizeof(int), 0);
    cr_assert_eq(world_add_resource(&world, &resource), 0);
    resource.type = 1;
    cr_assert_eq(world_add_resource(&world, &resource), 0);
    cr_assert_eq(world_remove_resource(&world, &resource), 0);
    cr_assert_eq(world_remove_resource(&world, &resource), -1);
    cr_assert_eq(world.resource_list.size(&world.resource_list), 1);
}

Test(world_world_remove_resource, world_world_remove_resource_by_type)
{
    world_t world;
    resource_t resource;

    resource.type = 0;
    vector_constructor(&world.resource_list, sizeof(int), 0);
    cr_assert_eq(world_add_resource(&world, &resource), 0);
    resource.type = 1;
    cr_assert_eq(world_add_resource(&world, &resource), 0);
    cr_assert_eq(world_remove_resource_by_type(&world, 0), 0);
    cr_assert_eq(world.resource_list.size(&world.resource_list), 1);
}

Test(world_world_remove_resource, world_world_remove_resource_by_type_failure)
{
    world_t world;
    resource_t resource;

    resource.type = 0;
    vector_constructor(&world.resource_list, sizeof(int), 0);
    cr_assert_eq(world_add_resource(&world, &resource), 0);
    resource.type = 1;
    cr_assert_eq(world_add_resource(&world, &resource), 0);
    cr_assert_eq(world_remove_resource_by_type(&world, 0), 0);
    cr_assert_eq(world_remove_resource_by_type(&world, 0), -1);
    cr_assert_eq(world.resource_list.size(&world.resource_list), 1);
}

Test(world_world_contains_resource, world_world_contains_resource_success)
{
    world_t world;
    resource_t resource;

    resource.type = 0;
    world_constructor(&world);
    world_add_resource(&world, &resource);
    cr_assert_eq(world_contains_resource(&world, &resource), true);
}

Test(world_world_contains_resource, world_world_contains_resource_failure)
{
    world_t world;
    resource_t resource;

    resource.type = 0;
    world_constructor(&world);
    cr_assert_eq(world_contains_resource(&world, &resource), false);
}

Test(world_world_contains_resource, world_world_contains_resource_by_type_success)
{
    world_t world;
    resource_t resource;

    resource.type = 0;
    world_constructor(&world);
    world_add_resource(&world, &resource);
    cr_assert_eq(world_contains_resource_by_type(&world, 0), true);
}

Test(world_world_contains_resource, world_world_contains_resource_by_type_failure)
{
    world_t world;
    resource_t resource;

    resource.type = 0;
    world_constructor(&world);
    world_add_resource(&world, &resource);
    cr_assert_eq(world_contains_resource_by_type(&world, 1), false);
}

Test(world_world_get_resource, world_world_get_resource_success)
{
    world_t world;
    resource_t resource;

    resource.type = 0;
    world_constructor(&world);
    world_add_resource(&world, &resource);
    cr_assert_neq(world_get_resource(&world, &resource), 0);
}

Test(world_world_get_resource, world_world_get_resource_failure)
{
    world_t world;
    resource_t resource;

    resource.type = 0;
    world_constructor(&world);
    world_add_resource(&world, &resource);
    resource.type = 1;
    cr_assert_eq(world_get_resource(&world, &resource), 0);
}

Test(world_world_get_resource, world_world_get_resource_by_id_success)
{
    world_t world;
    resource_t resource;

    resource.type = 0;
    world_constructor(&world);
    world_add_resource(&world, &resource);
    cr_assert_neq(world_get_resource_by_type(&world, 0), 0);
}

Test(world_world_get_resource, world_world_get_resource_by_id_failure)
{
    world_t world;
    resource_t resource;

    resource.type = 0;
    world_constructor(&world);
    world_add_resource(&world, &resource);
    cr_assert_eq(world_get_resource_by_type(&world, 1), 0);
}
