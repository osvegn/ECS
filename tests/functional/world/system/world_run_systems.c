/*
 * Filename: world_run_systems.c
 * Path: tests/functional/world/system
 * Created Date: Thursday, August 24th 2023, 11:50:03 pm
 * Author: osvegn
 * 
 * Copyright (c) 2023 ECS
 */

#include "world.h"
#include "world_system.h"

static int example(world_t *world) {
    int rvalue = 0;

    rvalue = world_run_systems(world);
    if (rvalue) {
        fprintf(stderr, "Error: world_run_systems() failed\n");
        return rvalue;
    }
    return 0;
}

static int example_run(void *ptr)
{
    return 0;
}

int main(void)
{
    world_t world;
    system_t system = {.active=true, .run=&example_run, .type=1};
    int rvalue = 0;

    world_constructor(&world, stdout);
    world_add_system(&world, &system);
    rvalue = example(&world);
    world_destructor(&world);
    return rvalue;
}
