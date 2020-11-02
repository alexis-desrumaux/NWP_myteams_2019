/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019
** File description:
** command
*/

#ifndef COMMAND_H_
#define COMMAND_H_

#include "client.h"
#include "keycodes.h"

//login/login.c
int login(client_t *client);
//login/login2.c
void free_response(char *uuid, char *name, lklist_char_t *answ,
lklist_str_t *p_answ);

//users/users.c
int users(client_t *client);
//users/users2.c
void print_infos_users(lklist_char_t *line);

//user/user.c
int user(client_t *client);
//user/user2.c
void c_user_free_str(lklist_char_t *r, lklist_str_t *p_r);

//send/send.c
int c_send(client_t *client);

//tools.c
int isquoted(lklist_char_t *ll);

//logout/logout.c
int c_logout(client_t *client);


#endif /* !COMMAND_H_ */
