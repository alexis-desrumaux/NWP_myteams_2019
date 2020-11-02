/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019
** File description:
** command
*/

#ifndef COMMAND_H_
#define COMMAND_H_

#include "mylib.h"
#include "server.h"
#include "keycodes.h"

//login/login.c
int login(server_t *server, client_t *client, lklist_str_t *pbuff);
//login/login2.c
void c_login_send_to_users(server_t *server, lklist_char_t *uuid,
lklist_char_t *name);
user_t *create_user(server_t *server, client_t *client, lklist_char_t *name);
void c_login_user_exist_print_event(server_t *server,
client_t *client, user_t *curr_u);

//users/users.c
int users(server_t *server, client_t *client, lklist_str_t *pbuff);
//users/users2.c
void send_r(client_t *client, lklist_char_t *infos);

//user/user.c
int user(server_t *server, client_t *client, lklist_str_t *pbuff);
//user/user_print.c
void print_user(client_t *client, user_t *u);

//send/send.c
int c_send(server_t *server, client_t *client, lklist_str_t *pbuff);
//send/send_msg.c
void c_send_u_n_exist(client_t *client, char *uuid);
void c_send_send_msg_to_cu(user_t *cu, client_t *client, lklist_char_t *body);
//send/send_msg_next.c
chat_t *c_send_create_new_chat(client_t *client,
user_t *friend, lklist_char_t *body);
void c_send_send_msg_to_friend(client_t *client,
user_t *cu, chat_t *curr_chat, lklist_char_t *body);
void c_send_print_events(client_t *client, user_t *friend, lklist_char_t *body);

//logout/logout.c
int c_logout(server_t *server, client_t *client, lklist_str_t *pbuff);
//logout/logout2.c
void c_logout_send_to_users(server_t *server, char *uuid, char *name);

//tools.c
int isquoted(lklist_char_t *ll);

#endif /* !COMMAND_H_ */
