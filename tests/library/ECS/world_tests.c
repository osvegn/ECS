/*
 * Filename: /home/osvegn/Documents/Repositories/ECS/tests/library/ECS/world_tests.c
 * Path: /home/osvegn/Documents/Repositories/ECS/tests/library/ECS
 * Created Date: Friday, April 21st 2023, 9:58:39 pm
 * Author: osvegn
 * 
 * Copyright (c) 2023 Your Company
 */

#include <criterion/criterion.h>
#include "world.h"
#include "world_system.h"

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

