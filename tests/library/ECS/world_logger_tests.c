/*
 * Filename: /home/osvegn/Documents/Repositories/ECS/tests/library/ECS/world_logger_tests.c
 * Path: /home/osvegn/Documents/Repositories/ECS/tests/library/ECS
 * Created Date: Tuesday, April 18th 2023, 8:34:03 pm
 * Author: osvegn
 * 
 * Copyright (c) 2023 Your Company
 */

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "world_logger.h"

void redirect_all_std(void)
{
    cr_redirect_stdout();
    cr_redirect_stderr();
}

Test(world_log_init, initialize_logger_with_stdout)
{
    world_log_init(stdout);
    world_log_destroy();
    cr_assert(true);
}

Test(world_log_init, initialize_logger_with_stderr)
{
    world_log_init(stderr);
    world_log_destroy();
    cr_assert(true);
}

Test(world_log_init, initialize_logger_with_null)
{
    world_log_init(0);
    world_log_destroy();
    cr_assert(true);
}

Test(world_log_init, initialize_logger_with_file)
{
    FILE *file = fopen("test.log", "w");
    world_log_init(file);
    world_log_destroy();
    cr_assert(true);
}

Test(world_log_init, initialize_logger_with_invalid_file)
{
    FILE *file = fopen("test.log", "r");
    world_log_init(file);
    world_log_destroy();
    cr_assert(true);
}

Test(world_log, log_debug_message)
{
    cr_redirect_stdout();
    world_log_init(stdout);
    cr_assert_eq(log_debug("test"), 0);
    world_log_destroy();
    cr_assert(true);
}

Test(world_log, log_info_message)
{
    cr_redirect_stdout();
    world_log_init(stdout);
    cr_assert_eq(log_info("test"), 0);
    world_log_destroy();
    cr_assert(true);
}

Test(world_log, log_warning_message)
{
    cr_redirect_stderr();
    world_log_init(stderr);
    cr_assert_eq(log_warn("test"), 0);
    world_log_destroy();
    cr_assert(true);
}

Test(world_log, log_error_message)
{
    cr_redirect_stderr();
    world_log_init(stderr);
    cr_assert_eq(log_error("test"), 0);
    world_log_destroy();
    cr_assert(true);
}

Test(world_log, log_fatal_message)
{
    cr_redirect_stderr();
    world_log_init(stderr);
    cr_assert_eq(log_fatal("test"), 0);
    world_log_destroy();
}

Test(world_log, log_debug_message_with_null_logger)
{
    cr_redirect_stdout();
    cr_assert_eq(log_debug("test"), -1);
}

Test(world_log, unknown_log_level)
{
    cr_redirect_stderr();
    world_log_init(stderr);
    cr_assert_eq(world_log(10, "test", 0, "test"), 0);
    world_log_destroy();
}
