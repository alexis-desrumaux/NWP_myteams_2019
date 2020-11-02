/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019
** File description:
** users2
*/

#include "mylib.h"
#include "command.h"

void send_r(client_t *client, lklist_char_t *infos)
{
    char *answ = infos->to_str(infos);

    dprintf(client->socket, "%s [ANSW]: %s\n", keycodes.valid_w_r, answ);
}