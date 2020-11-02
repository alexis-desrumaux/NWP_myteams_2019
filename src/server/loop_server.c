/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019
** File description:
** loop_server
*/

#include "server.h"
#include <signal.h>

int loop(server_t *server)
{
    while (1) {
        set_readfds(server);
        select(server->network->max + 1,
        &server->network->rdfs, NULL, NULL, NULL);
        watch_socket(server);
        watch_clients(server);
    }
    return 0;
}

int start_server(server_t *server)
{
    return loop(server);
}