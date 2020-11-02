/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019
** File description:
** user_print
*/

#include "mylib.h"
#include "command.h"

void c_user_send_infos(client_t *client, lklist_char_t *infos)
{
    char *infos_str = infos->to_str(infos);

    dprintf(client->socket, "%s [ANSW]: %s\n",
    keycodes.valid_w_r, infos_str);
    free(infos_str);
}

void print_user(client_t *client, user_t *u)
{
    char *uuid = u->uuid_str->to_str(u->uuid_str);
    char *name = u->name->to_str(u->name);
    char *log =  cv_lklist_to_nstring(int2char(u->logged));
    lklist_char_t *infos = lklist_char_init(NULL);

    for (size_t i = 0; uuid[i] != '\0'; i += 1)
        infos->push_back(infos, uuid[i]);
    infos->push_back(infos, ' ');
    for (size_t i = 0; name[i] != '\0'; i += 1)
        infos->push_back(infos, name[i]);
    infos->push_back(infos, ' ');
    for (size_t i = 0; log[i] != '\0'; i += 1)
        infos->push_back(infos, log[i]);
    free(uuid);
    free(name);
    free(log);
    c_user_send_infos(client, infos);
    infos->free(infos);
}