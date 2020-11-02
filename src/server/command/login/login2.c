/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019
** File description:
** login2
*/

#include "mylib.h"
#include "command.h"

void c_login_user_exist_print_event(server_t *server,
client_t *client, user_t *curr_u)
{
    char *name = curr_u->name->to_str(curr_u->name);
    char *uuid = curr_u->uuid_str->to_str(curr_u->uuid_str);

    curr_u->logged = 1;
    client->user = curr_u;
    client->logged = 1;
    server_event_user_logged_in(uuid);
    dprintf(client->socket, "%s [ANSW]: %s;%s\n",
    keycodes.valid_w_r, uuid, name);
    c_login_send_to_users(server, curr_u->uuid_str,
    curr_u->name);
    free(name);
    free(uuid);
}

void c_login_send_to_users(server_t *server, lklist_char_t *uuid,
lklist_char_t *name)
{
    client_t *curr = NULL;
    char *uuid_str = uuid->to_str(uuid);
    char *name_str = name->to_str(name);

    for (size_t i = 0; i != server->clients->size(server->clients); i += 1) {
        curr = (client_t *)server->clients->at(server->clients, i);
        if (curr->logged == 1 &&
        match_str(curr->user->uuid_str, uuid_str) == 0) {
            dprintf(curr->socket, "%s [ANSW]: %s %s\n",
            keycodes.user_connected, uuid_str, name_str);
        }
    }
    free(uuid_str);
    free(name_str);
}

void c_login_init_box(user_t *user)
{
    user->box = malloc(sizeof(box_t));
    user->box->chats = lklist_init();
}

void create_user_next(server_t *server, client_t *client, user_t *user)
{
    client->logged = 1;
    user->logged = 1;
    client->user = user;
    c_login_send_to_users(server, user->uuid_str, user->name);
}

user_t *create_user(server_t *server, client_t *client, lklist_char_t *name)
{
    user_t *user = malloc(sizeof(user_t));
    char *uuid = malloc(sizeof(char) * 37);
    lklist_char_t *nquot_name = NULL;

    nquot_name = catch_str(0, '"', name, '"');
    user->name = lklist_char_lklinit(nquot_name);
    nquot_name->free(nquot_name);
    uuid_generate_random(user->id);
    uuid_unparse(user->id, uuid);
    server_event_user_created(uuid, user->name->to_str(user->name));
    server_event_user_logged_in(uuid);
    dprintf(client->socket, "%s [ANSW]: %s;%s\n",
    keycodes.valid_w_r, uuid, user->name->to_str(user->name));
    user->uuid_str = cv_string_to_nlklist(uuid);
    c_login_init_box(user);
    create_user_next(server, client, user);
    return user;
}