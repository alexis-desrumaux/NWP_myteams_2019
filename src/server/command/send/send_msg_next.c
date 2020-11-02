/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019
** File description:
** send_msg_next
*/

#include "mylib.h"
#include "command.h"

void c_send_print_events(client_t *client, user_t *friend, lklist_char_t *body)
{
    char *uuid_cli = client->user->uuid_str->to_str(client->user->uuid_str);
    char *uuid_dest = friend->uuid_str->to_str(friend->uuid_str);
    char *body_str = body->to_str(body);

    server_event_private_message_sended(uuid_cli, uuid_dest, body_str);
    dprintf(client->socket, "%s\n", keycodes.valid_no_r);
    free(uuid_cli);
    free(uuid_dest);
    free(body_str);
}

void c_send_send_msg_to_friend(client_t *client, user_t *cu,
chat_t *curr_chat, lklist_char_t *body)
{
    sms_t *new_sms = malloc(sizeof(sms_t));

    new_sms->body = lklist_char_lklinit(body);
    new_sms->send_time = time(0);
    new_sms->user = client->user;
    curr_chat->sms->push_back(curr_chat->sms, new_sms, "sms_t *");
    c_send_print_events(client, cu, body);
    return;
}

chat_t *c_send_create_new_chat(client_t *client, user_t *friend,
lklist_char_t *body)
{
    chat_t *new_chat = malloc(sizeof(chat_t));
    sms_t *new_sms = malloc(sizeof(sms_t));

    new_chat->user1 = client->user;
    new_chat->user2 = friend;
    new_sms->body = lklist_char_lklinit(body);
    new_sms->send_time = time(0);
    new_sms->user = client->user;
    new_chat->sms = lklist_init();
    new_chat->sms->push_back(new_chat->sms, new_sms, "sms_t *");
    return new_chat;
}