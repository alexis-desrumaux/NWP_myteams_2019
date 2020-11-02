/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019
** File description:
** logout
*/

#include "mylib.h"
#include "command.h"

void c_logout_ctrlc_exec(server_t *server, client_t *client,
char *uuid, char *name)
{
    uuid = client->user->uuid_str->to_str(client->user->uuid_str);
    name = client->user->name->to_str(client->user->name);
    c_logout_send_to_users(server, uuid, name);
    server_event_user_logged_out(uuid);
    free(uuid);
    free(name);
}

void c_logout_command_exec(server_t *server, client_t *client,
char *uuid, char *name)
{
    uuid = client->user->uuid_str->to_str(client->user->uuid_str);
    name = client->user->name->to_str(client->user->name);
    dprintf(client->socket, "%s [ANSW]: %s %s\n",
    keycodes.exit, uuid, name);
    c_logout_send_to_users(server, uuid, name);
    server_event_user_logged_out(uuid);
    free(uuid);
    free(name);
}

int c_logout_exec(server_t *server, client_t *client, lklist_str_t *pbuff)
{
    char *uuid = NULL;
    char *name = NULL;

    if (client->user != NULL && client->logged == 1)
        client->user->logged = 0;
    if (match_str(pbuff->at(pbuff, 0), "^C") == 0) {
        if (client->user != NULL && client->logged == 1)
            c_logout_command_exec(server, client, uuid, name);
        else
            dprintf(client->socket, "%s\n", keycodes.exit);
    }
    else if (match_str(pbuff->at(pbuff, 0), "^C") == 1) {
        if (client->user != NULL && client->logged == 1)
            c_logout_ctrlc_exec(server, client, uuid, name);
    }
    return 1;
}

int c_logout_check_arg(client_t *client, lklist_str_t *pbuff)
{
    if (pbuff->size(pbuff) != 1)
        return 0;
    if (match_str(pbuff->at(pbuff, 0), "/logout") == 0 &&
    match_str(pbuff->at(pbuff, 0), "^C") == 0)
        return 0;
    return 1;
}

int c_logout(server_t *server, client_t *client, lklist_str_t *pbuff)
{
    int check = 0;

    check = c_logout_check_arg(client, pbuff);
    if (check == 0)
        return check;
    return c_logout_exec(server, client, pbuff);
}