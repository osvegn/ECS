/*
 * Filename: /workspaces/our_rpg/lib/ECS/source/world.c
 * Path: /workspaces/our_rpg/lib/ECS/source
 * Created Date: Wednesday, December 21st 2022, 8:20:21 am
 * Author: osvegn
 * 
 * Copyright (c) 2023 our_rpg
 */

#include "world.h"
#include <stddef.h>

int world_run_systems(world_t *world)
{
    vector_t *ptr = &world->system_list;
    system_t *system = NULL;
    unsigned int size = ptr->size(ptr);
    int rvalue = 0;

    for (unsigned int i = 0; i < size; i++) {
        system = ptr->at(ptr, i);
        if (system)
            rvalue = system->run((void *)world);
        else
            return -1;
        if (rvalue)
            return rvalue;
    }
    return 0;
}
