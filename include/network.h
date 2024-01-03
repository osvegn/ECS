/*
* Filename: network.h
* Path: include
* Created Date: Tuesday, January 02th 2024, 3:52 pm
* Author: osvegn
*
* Copyright (c) 2023 ECS
*/

#ifndef ECS_SERVER_H
#define ECS_SERVER_H

#include <sys/socket.h>
#include <netinet/in.h>
#include "vector.h"

typedef struct server_s {
    int socket;
    struct sockaddr_in address;
    socklen_t address_len;
    vector_t clients;
} server_t;

int server_constructor(server_t *server);
int server_destructor(server_t *server);
int server_bind(server_t *server);
int server_set_address(server_t *server, const char *ip, unsigned short port);
int server_listen(server_t *server, int backlog);

typedef struct client_s {
    int socket;
    struct sockaddr_in address;
    socklen_t address_len;
} client_t;

int client_constructor(client_t *client);
int client_destructor(client_t *client);
int client_connect(client_t *client);
int client_set_address(client_t *client, const char *ip, unsigned short port);

#endif // ECS_SERVER_H
