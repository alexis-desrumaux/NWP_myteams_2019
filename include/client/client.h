/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019
** File description:
** client
*/

#ifndef CLIENT_H_
#define CLIENT_H_

#include <sys/time.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <netdb.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <uuid/uuid.h>

#include "mylib.h"
#include "linkedlist.h"
#include "logging_client.h"

#define STDIN 0
#define SA struct sockaddr
#define MAX_NAME_LENGTH 32
#define MAX_DESCRIPTION_LENGTH 255
#define MAX_BODY_LENGTH 512

typedef int Socket;

typedef struct network_info_s
{
    Socket sockfd;
    struct sockaddr_in *sock_cli;
    fd_set rdfs;
    int max;
    uint16_t port;
} network_info_t;

typedef struct client_s
{
    network_info_t *network;
    lklist_char_t *server_answer;
    lklist_str_t *server_answer_p;
    lklist_char_t *client_answer;
    lklist_str_t *client_answer_p;
    int command_status;
    size_t curr_func;
    int (*command[16])(struct client_s *client);
    bool exit;
} client_t;

//clean_str.c
lklist_char_t *clean_str(lklist_char_t *str);

//display_help.c
void display_help(void);

//loop_client.c
int start_client(client_t *client);

//read.c
lklist_char_t *read_fd(int fd);

//tools.c
lklist_str_t *get_answ_server(lklist_char_t *buff);
int isquoted(lklist_char_t *ll);

//compute.c
int send_command(client_t *client);
int compute_get_answ_serv(client_t *client);

//compute2.c
int compute_get_answ_addinfos_logout(lklist_str_t *pr);
void free_command(client_t *client);

//create_commands.c
void create_commands(client_t *client);

//parse_command.c
lklist_str_t *parse_command(lklist_char_t *str);

#endif /* !CLIENT_H_ */
