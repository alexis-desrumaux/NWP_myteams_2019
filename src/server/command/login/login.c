/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019
** File description:
** login
*/

#include "mylib.h"
#include "command.h"

void c_login_check_user_exist_free(lklist_char_t *name,
char *name_str)
{
    name->free(name);
    free(name_str);
}

int c_login_check_user_exist(server_t *server, client_t *client,
lklist_str_t *pbuff)
{
    lklist_char_t *name = NULL;
    lklist_char_t *uuid = NULL;
    char *name_str = NULL;
    user_t *curr_u = NULL;
    int check = 0;

    if (server->users == NULL)
        return 0;
    name = catch_str(0, '"', pbuff->at(pbuff, 1), '"');
    name_str = name->to_str(name);
    for (size_t i = 0; i != server->users->size(server->users); i += 1) {
        curr_u = (user_t *)server->users->at(server->users, i);
        if (match_str(curr_u->name, name_str) == 1) {
            c_login_user_exist_print_event(server, client, curr_u);
            check = 1;
            break;
        }
    }
    c_login_check_user_exist_free(name, name_str);
    return check;
}

int check_arg_next(client_t *client, lklist_str_t *pbuff)
{
    if (pbuff->at(pbuff, 1)->size(pbuff->at(pbuff, 1)) <= 2) {
        dprintf(client->socket, "%s\n", keycodes.invalid);
        return 1;
    }
    if (client->logged == 1) {
        dprintf(client->socket, "%s\n", keycodes.already_exist);
        return 1;
    }
    return 2;
}

int check_arg(client_t *client, lklist_str_t *pbuff)
{
    if (pbuff->size(pbuff) != 2)
        return 0;
    if (match_str(pbuff->at(pbuff, 0), "/login") == 0)
        return 0;
    if (isquoted(pbuff->at(pbuff, 1)) == 0) {
        dprintf(client->socket, "%s\n", keycodes.invalid);
        return 1;
    }
    return check_arg_next(client, pbuff);
}

int login(server_t *server, client_t *client, lklist_str_t *pbuff)
{
    int check = 0;

    check = check_arg(client, pbuff);
    if (check == 0)
        return 0;
    else if (check == 1)
        return 1;
    if (c_login_check_user_exist(server, client, pbuff) == 0)
        server->users->push_back(server->users
        , create_user(server, client, pbuff->at(pbuff, 1)), "user_t *");
    return 1;
}