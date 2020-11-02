/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019
** File description:
** server
*/

#ifndef SERVER_H_
#define SERVER_H_

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
#include "logging_server.h"

#define STDIN 0
#define SA struct sockaddr
#define MAX_NAME_LENGTH 32
#define MAX_DESCRIPTION_LENGTH 255
#define MAX_BODY_LENGTH 512

typedef int Socket;

typedef struct user_s user_t;
typedef struct sms_s sms_t;
typedef struct chat_s chat_t;
typedef struct box_s box_t;
typedef struct comment_s comment_t;
typedef struct thread_s thread_t;
typedef struct channel_s channel_t;
typedef struct team_s teams_t;
typedef struct network_info_s network_info_t;
typedef struct client_s client_t;
typedef struct server_s server_t;

struct user_s
{
    uuid_t id;
    lklist_char_t *uuid_str;
    lklist_char_t *name;
    box_t *box;
    int logged;
};

struct sms_s
{
    time_t send_time;
    lklist_char_t *body;
    user_t *user;
};

struct chat_s
{
    user_t *user1;
    user_t *user2;
    lklist_t *sms;
};

struct box_s
{
    lklist_t *chats;
};

struct comment_s
{
    lklist_char_t *name;
    lklist_char_t *reply;
};

struct thread_s
{
    lklist_char_t *title;
    lklist_char_t *message;
    lklist_t *comments;
    uuid_t id;
};

struct channel_s
{
    lklist_char_t *title;
    lklist_char_t *desc;
    lklist_t *threads;
    uuid_t id;
};

struct team_s
{
    lklist_char_t *name;
    lklist_char_t *desc;
    lklist_t *channels;
    uuid_t id;
    lklist_t *users;
};

struct network_info_s
{
    Socket sockfd;
    Socket new_csock;
    struct sockaddr_in *new_cli;
    int max;
    fd_set rdfs;
    uint16_t port;
};

struct client_s
{
    Socket socket;
    struct sockaddr_in *info;
    int logged;
    user_t *user;
};

typedef struct server_s
{
    network_info_t *network;
    lklist_t *clients;
    lklist_t *users;
    lklist_t *teams;
    int (*command[16])(struct server_s *server,
    struct client_s *client, lklist_str_t *pbuff);
    lklist_str_t *save_file;
} server_t;

//display_help.c
void display_help();

//file_to_tab.c
lklist_str_t *file_to_tab(char *path);

//create_server.c
int create_sockfd(server_t *server);
void listen_socket(server_t *server);
void set_readfds(server_t *server);

//loop_server.c
void INThandler(int sig);
int start_server(server_t *server);

//tools.c
char *lklist_to_string(lklist_char_t *list);
void string_to_lklist(char *str, lklist_char_t *list);

//watchers.c
int watch_socket(server_t *server);
int watch_clients(server_t *server);

//close.c
void close_socket_connection(server_t *server, size_t cli_index);

//compute.c
void compute(server_t *server, client_t *client, lklist_char_t *buff);

//read.c
lklist_char_t *read_fd(int fd);

//parse_command.c
lklist_str_t *parse_command(lklist_char_t *str);

#endif /* !SERVER_H_ */
