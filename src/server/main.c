/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019
** File description:
** main
*/

#include "server.h"
#include "command.h"
#include <signal.h>

void create_commands(server_t *server)
{
    server->command[0] = login;
    server->command[1] = users;
    server->command[2] = user;
    server->command[3] = c_send;
    server->command[4] = c_logout;
    server->command[5] = NULL;
}

server_t *init_server(lklist_char_t *port)
{
    server_t *server = malloc(sizeof(server_t));

    server->save_file = file_to_tab("save.txt");
    server->network = malloc(sizeof(network_info_t));
    server->teams = lklist_init();
    server->users = lklist_init();
    server->clients = lklist_init();
    create_commands(server);
    server->network->sockfd = 0;
    server->network->new_csock = 0;
    server->network->port = (uint16_t)atoi(port->to_str(port));
    server->network->sockfd = create_sockfd(server);
    listen_socket(server);
    server->network->max = server->network->sockfd;
    if (server->save_file == NULL)
        return server;
    return server;
}

int main_check_argv(server_t *server, lklist_str_t *av, lklist_char_t *tmp)
{
    for (size_t i = 0; i != av->size(av) ; i++) {
        if (!isnumber(tmp->at(tmp, i)))
            return 84;
    }
    server = init_server(av->at(av, 1));
    start_server(server);
    return 0;
}

int main(int argc, char **argv)
{
    server_t *server = NULL;
    lklist_str_t *av = lklist_str_init(NULL);
    lklist_char_t *tmp = NULL;

    for (int i = 0; i != argc; i++)
        av->push_back(av, lklist_char_init(argv[i]));
    if (av->size(av) != 2)
        return 84;
    else if (av->size(av) == 2) {
        if (match_str(av->at(av, 1), "-help") == 1) {
            display_help();
            return 0;
        }
        tmp = av->at(av, 1);
        if (main_check_argv(server, av, tmp) == 84)
            return 84;
    }
    return 0;
}