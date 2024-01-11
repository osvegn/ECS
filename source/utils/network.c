/*
* Filename: network.c
* Path: source
* Created Date: Tuesday, January 2th 2024, 3:55 pm
* Author: osvegn
*
* Copyright (c) 2023 ECS
*/

#include "network.h"
#include "world_logger.h"
#include <arpa/inet.h>
#include <string.h>
#include <time.h>
#include <unistd.h>

/// Server

int server_constructor(server_t *server)
{
    log_info("Creating server");
    server->socket = 0;
    memset(&server->address, 0, sizeof(struct sockaddr_in));
    server->address_len = 0;
    server->socket = socket(AF_INET, SOCK_STREAM, 0);
    if (server->socket < 0)
        return -1;
    if (vector_constructor(&server->clients, sizeof(client_t), 0) < 0)
        return -1;
    log_info("Server created");
    return 0;
}

int server_destructor(server_t *server)
{
    log_info("Destroying server");
    close(server->socket);
    server->clients.destructor(&server->clients);
    return 0;
}

int server_bind(server_t *server)
{
    int rvalue = 0;

    log_info("Binding server");
    rvalue = bind(server->socket, (struct sockaddr*)&server->address, server->address_len);
    if (rvalue < 0)
        return -1;
    log_info("Server bound");
    return 0;
}

int server_set_address(server_t *server, const char *ip, unsigned short port)
{
    log_info("Setting server address");
    server->address.sin_family = AF_INET;
    server->address.sin_addr.s_addr = inet_addr(ip);
    server->address.sin_port = htons(port);
    server->address_len = sizeof(server->address);
    log_info("Server address set");
    return 0;
}

int server_listen(server_t *server, int backlog)
{
    int rvalue = 0;

    log_info("Listening server");
    rvalue = listen(server->socket, backlog);
    if (rvalue < 0)
        return -1;
    log_info("Server listening");
    return 0;
}

int server_accept(server_t *server)
{
    client_t client = {0};

    log_info("Accepting connection...");
    client.socket = accept(server->socket, (struct sockaddr *)&client.address, &client.address_len);
    client.is_connected = (client.socket > 0);
    client.created_at = time(0);
    server->clients.emplace_back(&server->clients, &client);
    log_info("Connection accepted");
    return client.socket;
}

/// Client

int client_constructor(client_t *client)
{
    log_info("Creating client");
    client->socket = 0;
    memset(&client->address, 0, sizeof(struct sockaddr_in));
    client->address_len = 0;
    client->socket = socket(AF_INET, SOCK_STREAM, 0);
    client->created_at = time(0);
    client->is_connected = false;
    if (client->socket < 0)
        return -1;
    log_info("Client created");
    return 0;
}

int client_destructor(client_t *client)
{
    log_info("Destroying client");
    close(client->socket);
    return 0;
}

int client_connect(client_t *client)
{
    int rvalue = 0;

    log_info("Connecting client");
    rvalue = connect(client->socket, (struct sockaddr *)&client->address, client->address_len);
    if (rvalue < 0)
        return -1;
    client->created_at = time(0);
    client->is_connected = true;
    log_info("Client connected");
    return 0;
}

int client_set_address(client_t *client, const char *ip, unsigned short port)
{
    log_info("Setting client address");
    client->address.sin_family = AF_INET;
    client->address.sin_addr.s_addr = inet_addr(ip);
    client->address.sin_port = htons(port);
    client->address_len = sizeof(client->address);
    log_info("Client address set");
    return 0;
}
