
#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "world_logger.h"

Test(test01, test01)
{
    world_log_init(stdout);
}

Test(test02, test02)
{
    world_log_init(stdout);
    world_log(0, __FILE__, 0, "Hello World");
}