/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019
** File description:
** compute
*/

#include "mylib.h"
#include "server.h"
#include "command.h"

void compute(server_t *server, client_t *client, lklist_char_t *buff)
{
    lklist_str_t *pbuff = parse_command(buff);
    int check = 0;

    for (size_t i = 0; server->command[i] != NULL && pbuff != NULL; i += 1) {
        check = server->command[i](server, client, pbuff);
        if (check == 1)
            break;
    }
    if (check == 0)
        dprintf(client->socket, "%s\n", keycodes.invalid);
    for (size_t i = 0; i != pbuff->size(pbuff); i += 1)
        pbuff->at(pbuff, i)->free(pbuff->at(pbuff, i));
    pbuff->free(pbuff);
    return;
}