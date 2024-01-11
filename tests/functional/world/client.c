#include "network.h"

int main(int ac, char **av)
{
    client_t client;
    int rvalue = 0;

    world_log_init(0);
    client_constructor(&client);
    if (client_set_address(&client, "0.0.0.0", 8080) < 0)
        rvalue = 1;
    if (client_connect(&client) < 0)
        rvalue = 2;
    client_destructor(&client);
    return rvalue;
}
