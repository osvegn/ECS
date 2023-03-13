/*
 * Filename: /home/thomas/Documents/Perso/our_rpg/lib/ECS/include/world_resource.h
 * Path: /home/thomas/Documents/Perso/our_rpg/lib/ECS/include
 * Created Date: Wednesday, March 8th 2023, 11:06:07 pm
 * Author: Thomas
 *
 * Copyright (c) 2023 Your Company
 */

#ifndef WORLD_RESOURCE_H_
#define WORLD_RESOURCE_H_

#include "world.h"
#include "resource.h"

/// @brief It adds a resource to the world's resource list
/// @param world The world object
/// @param resource The resource to add to the world.
/// @return 0, or -1 if the resource already exists.
/// @note See resource.h for more information about resources.
/// @details **Example:**
/// @code
///    int example(world_t *world)
///    {
///        int rvalue = 0;
///        resource_t resource = {1, 0};
///
///        rvalue = world_add_resource(world, &resource);
///        if (rvalue < 0) {
///            fprintf(stderr, "Error: world_add_resource() failed: resource already exists\n");
///            return -1;
///        }
///        return 0;
///    }
/// @endcode
int world_add_resource(world_t *world, resource_t *resource);

/// @brief It removes a resource from the world's resource list
/// @param world The world that the resource is in.
/// @param resource The resource to be removed.
/// @return 0, or -1 if the resource isn't found.
/// @note Prefer using world_remove_resource_by_type() instead.
/// @details **Example:**
/// @code
///    int example(world_t *world)
///    {
///        int rvalue = 0;
///        resource_t resource = {1, 0};
///
///        rvalue = world_remove_resource(world, &resource);
///        if (rvalue < 0) {
///            fprintf(stderr, "Error: world_remove_resource() failed: resource not found\n");
///            return -1;
///        }
///        return 0;
///    }
/// @endcode
int world_remove_resource(world_t *world, resource_t *resource);

/// @brief It removes a resource from the world's resource list.
/// @param world The world that the resource is in.
/// @param type The resource type to be removed.
/// @return 0, or -1 if the resource isn't found.
/// @details **Example:**
/// @code
///    int example(world_t *world)
///    {
///        int rvalue = 0;
///
///        rvalue = world_remove_resource_by_type(world, RESOURCE_TYPE_EXAMPLE);
///        if (rvalue < 0) {
///            fprintf(stderr, "Error: world_remove_resource_by_type() failed: resource not found\n");
///            return -1;
///        }
///        return 0;
///    }
/// @endcode
int world_remove_resource_by_type(world_t *world, unsigned int type);

/// @brief It returns true if the resource is in the world's resource list
/// @param world The world that contains the resource.
/// @param resource The resource to check for.
/// @return A boolean value.
/// @note Prefer using world_contains_resource_by_type() instead.
/// @details **Example:**
/// @code
///    int example(world_t *world)
///    {
///        resource_t resource = {1, 0};
///
///        if (world_contains_resource(world, &resource)) {
///            printf("The resource is in the world's resource list\n");
///        } else {
///            printf("The resource isn't in the world's resource list\n");
///        }
///        return 0;
///    }
/// @endcode
bool world_contains_resource(world_t *world, resource_t *resource);

/// @brief It returns if the resource is in the world's resource list or not.
/// @param world The world that contains the resource.
/// @param type The resource type to check for.
/// @return True if the resource is found, false otherwise.
/// @details **Example:**
/// @code
///    int example(world_t *world)
///    {
///        if (world_contains_resource_by_type(world, RESOURCE_TYPE_EXAMPLE)) {
///            printf("The resource is in the world's resource list\n");
///        } else {
///            printf("The resource isn't in the world's resource list\n");
///        }
///        return 0;
///    }
/// @endcode
bool world_contains_resource_by_type(world_t *world, unsigned int type);

/// @brief It returns the resource contained in the world corresponding on the resource passed as parameter.
/// @param world The world on which get the resource.
/// @param resource The resource to be found.
/// @return It returns a pointer to the resource asked, or 0 if it's not found.
/// @note Prefer using world_get_resource_by_type() instead.
/// @details **Example:**
/// @code
///    int example(world_t *world)
///    {
///        resource_t resource = {1, 0};
///        resource_t *resource_found = 0;
///
///        resource_found = world_get_resource(world, &resource);
///        if (resource_found == 0) {
///            fprintf(stderr, "Error: world_get_resource() failed: resource not found\n");
///            return -1;
///        }
///        return 0;
///    }
/// @endcode
resource_t *world_get_resource(world_t *world, resource_t *resource);

/// @brief It returns the resource contained in the world corresponding on the resource type passed as parameter.
/// @param world The world on which get the resource.
/// @param type The resource to be found.
/// @return It returns a pointer to the resource asked, or 0 if it's not found.
/// @details **Example:**
/// @code
///    int example(world_t *world)
///    {
///        resource_t *resource_found = 0;
///
///        resource_found = world_get_resource_by_type(world, RESOURCE_TYPE_EXAMPLE);
///        if (resource_found == 0) {
///            fprintf(stderr, "Error: world_get_resource_by_type() failed: resource not found\n");
///            return -1;
///        }
///        return 0;
///    }
/// @endcode
resource_t *world_get_resource_by_type(world_t *world, unsigned int type);

#endif