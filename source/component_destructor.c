/*
 * Filename:
 * source/component_destructor.c
 * Path: source
 * Created Date: Sunday, February 12th 2023, 5:21:14 pm
 * Author: Thomas
 *
 * Copyright (c) 2023 Your Company
 */

#include "component.h"
#include "world_logger.h"
#include <stdlib.h>

void component_destructor(component_t *c)
{
    if (c->data)
        free(c->data);
    c->data = 0;
    log_debug("Component %d destroyed", c->type);
}
