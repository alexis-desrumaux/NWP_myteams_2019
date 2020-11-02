/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019
** File description:
** send_msg
*/

#include "mylib.h"
#include "command.h"

void c_send_new_chat_w_u(client_t *client, user_t *friend, lklist_char_t *body)
{
    lklist_t *chats_c = client->user->box->chats;
    chat_t *new_chat = NULL;

    new_chat = c_send_create_new_chat(client, friend, body);
    chats_c->push_back(chats_c, new_chat, "chat_t *");
    friend->box->chats->push_back(friend->box->chats, new_chat, "chat_t *");
    c_send_print_events(client, friend, body);
}

chat_t *c_send_is_a_chat_w_u_cond(lklist_t *chats_cli,
user_t *cu, client_t *client, size_t i)
{
    chat_t *curr_chat_cli = NULL;
    char *uuid_friend = cu->uuid_str->to_str(cu->uuid_str);

    curr_chat_cli = (chat_t *)chats_cli->at(chats_cli, i);
    if (match_str(client->user->uuid_str, uuid_friend) == 1 &&
    match_str(curr_chat_cli->user1->uuid_str, uuid_friend) == 1
    && match_str(curr_chat_cli->user2->uuid_str, uuid_friend) == 1) {
        free(uuid_friend);
        return curr_chat_cli;
    }
    else if (match_str(curr_chat_cli->user1->uuid_str, uuid_friend) == 1 ||
    match_str(curr_chat_cli->user2->uuid_str, uuid_friend) == 1) {
        free(uuid_friend);
        return curr_chat_cli;
    }
    free(uuid_friend);
    return NULL;
}

chat_t *c_send_is_a_chat_w_u(lklist_t *chats_cli,
user_t *cu, client_t *client)
{
    chat_t *curr_chat_cli = NULL;
    bool check = false;

    if (chats_cli->size(chats_cli) == 0)
        return NULL;
    for (size_t i = 0; i != chats_cli->size(chats_cli); i += 1) {
        curr_chat_cli =
        c_send_is_a_chat_w_u_cond(chats_cli, cu, client, i);
        if (curr_chat_cli != NULL) {
            check = true;
            break;
        }
    }
    if (check == false)
        return NULL;
    return curr_chat_cli;
}

void c_send_send_msg_to_cu(user_t *cu, client_t *client, lklist_char_t *body)
{
    char *body_str = body->to_str(body);
    lklist_t *chats_c = client->user->box->chats;
    chat_t *chat_w_usr = NULL;

    if (body->size(body) > MAX_BODY_LENGTH) {
        dprintf(client->socket, "%s [ANSW]: %s\n",
        keycodes.too_long_body, body_str);
        free(body_str);
        return;
    }
    free(body_str);
    chat_w_usr = c_send_is_a_chat_w_u(chats_c, cu, client);
    if (chat_w_usr == NULL)
        c_send_new_chat_w_u(client, cu, body);
    if (chat_w_usr != NULL)
        c_send_send_msg_to_friend(client, cu, chat_w_usr, body);
}

void c_send_u_n_exist(client_t *client, char *uuid)
{
    dprintf(client->socket, "%s [ANSW]: %s\n",
    keycodes.user_n_exist, uuid);
}