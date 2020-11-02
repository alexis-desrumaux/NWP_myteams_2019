/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019
** File description:
** close
*/

#include "server.h"

void close_socket_connection(server_t *server, size_t cli_index)
{
    client_t *client = server->clients->at(server->clients, cli_index);

    printf("[EPITECH TEAMS] Client %s PORT: %d disconnected\n",
    inet_ntoa(client->info->sin_addr),
    ntohs(client->info->sin_port));
    dprintf(client->socket, "%s", "close connection");
    close(client->socket);
    server->clients->erase(server->clients, cli_index);
}