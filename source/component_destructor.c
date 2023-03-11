/*
 * Filename: /home/thomas/Documents/Perso/our_rpg/lib/ECS/source/component_destructor.c
 * Path: /home/thomas/Documents/Perso/our_rpg/lib/ECS/source
 * Created Date: Sunday, February 12th 2023, 5:21:14 pm
 * Author: Thomas
 *
 * Copyright (c) 2023 Your Company
 */

#include "component.h"
#include <stdlib.h>

void component_destructor(component_t *c)
{
    if (c->data)
        free(c->data);
    c->data = 0;
}
