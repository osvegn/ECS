/*
 * Filename: main.c
 * Path: functional
 * Created Date: Friday, August 18th 2023, 10:19:27 pm
 * Author: osvegn
 * 
 * Copyright (c) 2023 ECS
 */

#include <unistd.h>
#include <sys/types.h>
#include <signal.h>
#include "world.h"

int test_world_destructor_with_entity(void)
{
    world_t world;
    entity_t entity = {0};
    component_t component = {.type=1};

    entity_constructor(&entity);
    entity_add_component(&entity, &component);
    world_constructor(&world, stdout);
    world.entity_list.emplace_back(&world.entity_list, &entity);
    if (world.entity_list.size(&world.entity_list) != 1)
        return 1;
    world_destructor(&world);
    if (world.entity_list.size(&world.entity_list) != 0)
        return 1;
    return 0;
}

int test_world_destructor_with_resource(void)
{
    world_t world;
    resource_t resource = {.type=1};

    world_constructor(&world, stdout);
    world_add_resource(&world, &resource);
    if (world.resource_list.size(&world.resource_list) != 1)
        return 1;
    world_destructor(&world);
    if (world.resource_list.size(&world.resource_list) != 0)
        return 1;
    return 0;
}

int (*tests [])(void) = {
    &test_world_destructor_with_entity,
    &test_world_destructor_with_resource,
    0
};

static void sig_handler(int signo)
{
    printf("Catching: %i\n", signo);
    exit(signo);
}

int run_subprocess(int (*test)(void))
{
    pid_t pid = fork();
    int status = 0;

    if (pid < 0) {
        return -1;
    } else if (pid == 0) {
        if (signal(SIGSEGV, sig_handler) == SIG_ERR) {
            printf("\nCan't catch SIGSEGV\n");
            exit(1);
        }
        exit(test());
    }
    wait(&status);
    return status;
}

int main(void)
{
    int res = 0;
    int failure = 0;
    int i = 0;

    printf("Start functional tests:\n");
    for (i = 0; tests[i]; i++) {
        printf("Launch functional tests: %i\n", i);
        res = run_subprocess(tests[i]);
        if (res)
            failure++;
        printf("Test %i: %s\n", i, (res) ? "Failure" : "Success");
    }
    printf("End functional tests:\n");
    printf("%i/%i failure.\n", failure, i);
    return 0;
}
