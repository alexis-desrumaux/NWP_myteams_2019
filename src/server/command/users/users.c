/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019
** File description:
** users
*/

#include "mylib.h"
#include "command.h"

void list_users_next2(lklist_char_t *infos,
user_t *cu, lklist_char_t *logged)
{
    for (size_t i = 0; i != cu->name->size(cu->name); i += 1)
        infos->push_back(infos, cu->name->at(cu->name, i));
    infos->push_back(infos, ' ');
    for (size_t i = 0; i != logged->size(logged); i += 1)
        infos->push_back(infos, logged->at(logged, i));
}

lklist_char_t *list_users_next(lklist_t *u, lklist_char_t *infos, user_t *cu,
lklist_char_t *logged)
{
    for (size_t i = 0; i != u->size(u); i += 1) {
        if (i != 0)
            infos->push_back(infos, ';');
        cu = ((user_t *)u->at(u, i));
        logged = int2char(cu->logged);
        for (size_t i = 0; i !=
        cu->uuid_str->size(cu->uuid_str); i += 1)
            infos->push_back(infos, cu->uuid_str->at(cu->uuid_str, i));
        infos->push_back(infos, ' ');
        list_users_next2(infos, cu, logged);
        logged->free(logged);
    }
    return infos;
}

lklist_char_t *list_users(server_t *server)
{
    lklist_char_t *infos = lklist_char_init(NULL);
    lklist_t *u = server->users;
    lklist_char_t *logged = NULL;
    user_t *cu = NULL;

    if (u->size(u) == 0) {
        infos->push_back(infos, '-');
        return infos;
    }
    return list_users_next(u, infos, cu, logged);
}

int u_check_arg(client_t *client, lklist_str_t *pbuff)
{
    if (pbuff->size(pbuff) != 1)
        return 0;
    if (match_str(pbuff->at(pbuff, 0), "/users") == 0)
        return 0;
    if (client->logged == 0) {
        dprintf(client->socket, "%s\n", keycodes.unauthorised);
        return 1;
    }
    return 2;
}

int users(server_t *server, client_t *client, lklist_str_t *pbuff)
{
    int check = 0;

    check = u_check_arg(client, pbuff);
    if (check == 0)
        return 0;
    if (check == 1)
        return 1;
    send_r(client, list_users(server));
    return 1;
}