/*
 * Filename: world_tests.c
 * Path: tests/library/ECS
 * Created Date: Friday, April 21st 2023, 9:58:39 pm
 * Author: osvegn
 *
 * Copyright (c) 2023 ECS
 */

#include <criterion/criterion.h>
#include "world.h"
#include "world_system.h"
#include "world_resource.h"

Test(world, world_run_systems_success)
{
    world_t world;

    cr_assert_eq(world_constructor(&world, 0), 0);
    cr_assert_eq(world_run_systems(&world), 0);
    world_destructor(&world);
}

Test(world, world_run_systems_failure)
{
    world_t world;
    system_t system = {.run = NULL};

    cr_assert_eq(world_constructor(&world, 0), 0);
    world_add_system(&world, &system);
    cr_assert_eq(world_run_systems(&world), -1);
    world_destructor(&world);
}

Test(world, world_run_systems_failure_2)
{
    world_t world;
    system_t system = {.run = (int (*)(void *))1};

    cr_assert_eq(world_constructor(&world, 0), 0);
    world.system_list.emplace_back(&world.system_list, &system);
    world.system_list.pointer = 0;
    cr_assert_eq(world_run_systems(&world), -1);
    world_destructor(&world);
}

static int system_test_run(void *world)
{
    return -1;
}

Test(world, world_run_systems_failure_3)
{
    world_t world;
    system_t system = {.run = system_test_run};

    cr_assert_eq(world_constructor(&world, 0), 0);
    world_add_system(&world, &system);
    cr_assert_eq(world_run_systems(&world), -1);
    world_destructor(&world);
}

Test(world_destructor, world_destructor_without_resource_destructor)
{
    world_t world;
    resource_t resource = {.data=0, .destructor=0, .type=1};

    world_constructor(&world, stdout);
    world_add_resource(&world, &resource);
    world_destructor(&world);
    cr_assert_eq(1, 1);
}

static int r_destructor(resource_t *data)
{
    if (data->data)
        free(data->data);
    return 0;
}

Test(world_destructor, world_destructor_with_resource_destructor)
{
    world_t world;
    resource_t resource = {.data=0, .destructor=&r_destructor, .type=1};

    world_constructor(&world, stdout);
    world_add_resource(&world, &resource);
    world_destructor(&world);
    cr_assert_eq(1, 1);
}
