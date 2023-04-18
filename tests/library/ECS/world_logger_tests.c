
#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "world_logger.h"

void redirect_all_stdout(void)
{
    cr_redirect_stdout();
    cr_redirect_stderr();
}

Test(test01, test01)
{
    world_log_init(stdout);
}