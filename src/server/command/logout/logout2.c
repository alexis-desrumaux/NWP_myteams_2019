/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019
** File description:
** logout2
*/

#include "mylib.h"
#include "command.h"

void c_logout_send_to_users(server_t *server, char *uuid, char *name)
{
    client_t *curr = NULL;

    for (size_t i = 0; i != server->clients->size(server->clients); i += 1) {
        curr = (client_t *)server->clients->at(server->clients, i);
        if (curr->logged == 1 && match_str(curr->user->uuid_str, uuid) == 0) {
            dprintf(curr->socket, "%s [ANSW]: %s %s\n",
            keycodes.user_disconnected, uuid, name);
        }
    }
}