/*
 * Filename: /workspaces/our_rpg/tests/library/ECS/world_constructor_tests.c
 * Path: /workspaces/our_rpg/tests/library/ECS
 * Created Date: Monday, January 2nd 2023, 2:38:37 pm
 * Author: osvegn
 * 
 * Copyright (c) 2023 our_rpg
 */

#include <criterion/criterion.h>
#include "world.h"

Test(world_constructor, world_constructor)
{
    world_t world;

    cr_assert_eq(world_constructor(&world, stdout), 0);
    world_destructor(&world);
}
