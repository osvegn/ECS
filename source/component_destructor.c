/*
 * Filename: component_destructor.c
 * Path: source
 * Created Date: Sunday, February 12th 2023, 5:21:14 pm
 * Author: osvegn
 *
 * Copyright (c) 2023 ECS
 */

#include "component.h"
#include "world_logger.h"
#include <stdlib.h>

void component_destructor(component_t *c)
{
    log_info("Component (%d) destructor called", c->type);
    if (c->data)
        free(c->data);
    c->data = 0;
}
