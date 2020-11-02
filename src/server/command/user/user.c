/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019
** File description:
** user
*/

#include "mylib.h"
#include "command.h"

void check_cond_user(client_t *client, user_t *u, int check,
lklist_char_t *uuid)
{
    char *uuid_str = uuid->to_str(uuid);

    if (check == 0) {
        dprintf(client->socket, "%s [ANSW]: %s\n",
        keycodes.user_n_exist, uuid_str);
        return;
    }
    free(uuid_str);
    print_user(client, u);
    return;
}

void get_user(server_t *server, client_t *client, lklist_str_t *pbuff)
{
    lklist_char_t *arg = pbuff->at(pbuff, 1);
    lklist_char_t *uuid = catch_str(0, '"', arg, '"');
    char *uuid_str = uuid->to_str(uuid);
    lklist_t *u = server->users;
    user_t *cu = NULL;
    int check = 0;

    for (size_t i = 0; i != u->size(u); i += 1) {
        cu = ((user_t *)u->at(u, i));
        if (match_str(cu->uuid_str, uuid_str) == 1) {
            check = 1;
            break;
        }
    }
    free(uuid_str);
    check_cond_user(client, cu, check, uuid);
    uuid->free(uuid);
}

int check_command_user_arg2(client_t *client, lklist_str_t *pbuff)
{
    if (isquoted(pbuff->at(pbuff, 1)) == 0)
        return 0;
    if (client->logged == 0) {
        dprintf(client->socket, "%s\n", keycodes.unauthorised);
        return 1;
    }
    return 2;
}

int check_command_user_arg(client_t *client, lklist_str_t *pbuff)
{
    if (pbuff->size(pbuff) != 2)
        return 0;
    if (match_str(pbuff->at(pbuff, 0), "/user") == 0)
        return 0;
    if (pbuff->at(pbuff, 1)->size(pbuff->at(pbuff, 1)) <= 2)
        return 0;
    return check_command_user_arg2(client, pbuff);
}

int user(server_t *server, client_t *client, lklist_str_t *pbuff)
{
    int check = 0;

    check = check_command_user_arg(client, pbuff);
    if (check == 0 || check == 1)
        return check;
    get_user(server, client, pbuff);
    return 1;
}