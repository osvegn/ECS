#include "network.h"
#include <arpa/inet.h>

int main(void)
{
    server_t server;
    client_t client;
    int rvalue = 0;

    world_log_init(0);
    server_constructor(&server);
    if (server_set_address(&server, "0.0.0.0", 8080) < 0)
        rvalue = -1;
    printf("server.address.sin_family = %d\n", server.address.sin_family);
    printf("server.address.sin_addr.s_addr = %s\n", inet_ntoa(server.address.sin_addr));
    printf("server.address.sin_port = %d\n", server.address.sin_port);
    if (server_bind(&server) < 0)
        rvalue = -1;
    if (server_listen(&server, 10) < 0)
        rvalue = -1;
    client_constructor(&client);
    client.socket = accept(server.socket, (struct sockaddr *)&client.address, &client.address_len);
    server.clients.emplace_back(&server.clients, &client);
    server_destructor(&server);
}