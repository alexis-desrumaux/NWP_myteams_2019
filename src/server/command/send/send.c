/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019
** File description:
** send
*/

#include "mylib.h"
#include "command.h"

void c_send_send_msg_free(lklist_char_t *uuid,
lklist_char_t *body, char *uuid_str)
{
    uuid->free(uuid);
    body->free(body);
    free(uuid_str);
}

void c_send_send_msg(server_t *server, client_t *client, lklist_str_t *pbuff)
{
    lklist_char_t *uuid = catch_str(0, '"', pbuff->at(pbuff, 1), '"');
    lklist_char_t *body = catch_str(0, '"', pbuff->at(pbuff, 2), '"');
    char *uuid_str = uuid->to_str(uuid);
    lklist_t *u = server->users;
    user_t *cu = NULL;
    int check = 0;

    for (size_t i = 0; i != u->size(u); i += 1) {
        cu = (user_t *)u->at(u, i);
        if (match_str(cu->uuid_str, uuid_str) == 1) {
            c_send_send_msg_to_cu(cu, client, body);
            check = 1;
            break;
        }
    }
    if (check == 0)
        c_send_u_n_exist(client, uuid_str);
    c_send_send_msg_free(uuid, body, uuid_str);
}

int c_send_check_arg2(client_t *client, lklist_str_t *pbuff)
{
    if (isquoted(pbuff->at(pbuff, 1)) == 0 ||
    isquoted(pbuff->at(pbuff, 2)) == 0)
        return 0;
    if (client->logged == 0) {
        dprintf(client->socket, "%s\n", keycodes.unauthorised);
        return 1;
    }
    return 2;
}

int c_send_check_arg(client_t *client, lklist_str_t *pbuff)
{
    if (pbuff->size(pbuff) != 3)
        return 0;
    if (match_str(pbuff->at(pbuff, 0), "/send") == 0)
        return 0;
    if (pbuff->at(pbuff, 1)->size(pbuff->at(pbuff, 1)) <= 2)
        return 0;
    if (pbuff->at(pbuff, 2)->size(pbuff->at(pbuff, 2)) <= 2)
        return 0;
    return c_send_check_arg2(client, pbuff);
}

int c_send(server_t *server, client_t *client, lklist_str_t *pbuff)
{
    int check = 0;

    check = c_send_check_arg(client, pbuff);
    if (check == 0 || check == 1)
        return check;
    c_send_send_msg(server, client, pbuff);
    return 1;
}