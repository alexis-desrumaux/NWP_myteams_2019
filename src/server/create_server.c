/*
** EPITECH PROJECT, 2020
** NWP_myftp_2019
** File description:
** create_server
*/

#include "server.h"

void set_readfds(server_t *server)
{
    server->network->max = server->network->sockfd;
    FD_ZERO(&server->network->rdfs);
    FD_SET(server->network->sockfd, &server->network->rdfs);

    for (size_t i = 0; i != server->clients->size(server->clients); i += 1) {
        server->network->max =
        ((client_t *)server->clients->at(server->clients, i))->socket >
        server->network->max ?
        ((client_t *)server->clients->at(server->clients, i))->socket :
        server->network->max;
        FD_SET(((client_t *)server->clients->at(server->clients, i))->socket,
        &server->network->rdfs);
    }
}

void listen_socket(server_t *server)
{
    if (listen(server->network->sockfd, 5) != 0) {
        printf("[EPITECH TEAMS] Listen failed...\n");
        exit(0);
    }
    printf("[EPITECH TEAMS] Server listening..\n");
}

int bind_socketfd_ip(int sockfd, struct sockaddr_in *servaddr, uint16_t port)
{
    servaddr->sin_family = AF_INET;
    servaddr->sin_addr.s_addr = htonl(INADDR_ANY);
    servaddr->sin_port = htons(port);

    bind(sockfd, (SA*)&*servaddr, sizeof(*servaddr));
    return sockfd;
}

int create_sockfd(server_t *server)
{
    int sockfd = 0;
    struct sockaddr_in *servaddr = malloc(sizeof(struct sockaddr_in));

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        printf("[EPITECH TEAMS] Socket creation failed...\n");
        exit(0);
    }
    else
        printf("[EPITECH TEAMS] Socket successfully created..\n");
    bzero(&*servaddr, sizeof(*servaddr));
    return bind_socketfd_ip(sockfd, servaddr, server->network->port);
}