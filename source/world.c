/*
 * Filename: world.c
 * Path: source
 * Created Date: Wednesday, December 21st 2022, 8:20:21 am
 * Author: osvegn
 *
 * Copyright (c) 2023 ECS
 */

#include "world.h"
#include <stddef.h>

int world_run_systems(world_t *world)
{
    vector_t *systems = &world->system_list;
    system_t *system = NULL;
    unsigned int size = systems->size(systems);
    int rvalue = 0;

    for (unsigned int i = 0; i < size && rvalue == 0; i++) {
        system = systems->at(systems, i);
        if (system && system->run)
            rvalue = system->run((void *)world);
        else
            rvalue = -1;
    }
    return rvalue;
}
