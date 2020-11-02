/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019
** File description:
** main
*/

#include "client.h"
#include "command_cli.h"

int create_client(client_t *client, lklist_char_t *ip, lklist_char_t *port)
{
    client->network->sockfd = 0;
    client->network->sock_cli = malloc(sizeof(struct sockaddr_in));
    client->network->port = (uint16_t)my_putint(port);
    if ((client->network->sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        printf("%s\n", "CLIENT SOCKET FAILED");
        return -1;
    }
    bzero(&*client->network->sock_cli, sizeof(*client->network->sock_cli));
    client->network->sock_cli->sin_family = AF_INET;
    client->network->sock_cli->sin_port = htons(client->network->port);
    client->network->sock_cli->sin_addr.s_addr = inet_addr(ip->to_str(ip));
    if (connect(client->network->sockfd, (SA*)&*client->network->sock_cli,
    sizeof(*client->network->sock_cli)) == -1) {
        return -1;
    }
    return 0;
}

client_t *init_client_connection(lklist_char_t *ip, lklist_char_t *port)
{
    client_t *client = malloc(sizeof(client_t));

    client->network = malloc(sizeof(network_info_t));
    client->network->max = 0;
    create_commands(client);
    client->command_status = 0;
    client->curr_func = -1;
    client->exit = false;
    if (create_client(client, ip, port) == -1) {
        free(client->network);
        free(client);
        exit(84);
    }
    return client;
}

int check_argv_p2(lklist_str_t *argv)
{
    lklist_char_t *tmp = NULL;

    tmp = argv->at(argv, 1);
    for (size_t i = 0; i != tmp->size(tmp); i++) {
        if (!isnumber(tmp->at(tmp, i)) && tmp->at(tmp, i) != '.')
            return 84;
    }
    tmp = argv->at(argv, 2);
    for (size_t i = 0; i != tmp->size(tmp); i++) {
        if (!isnumber(tmp->at(tmp, i)))
            return 84;
    }
    return 0;
}

int check_argv(lklist_str_t *argv)
{
    if (argv->size(argv) < 2)
        return 84;
    if (argv->size(argv) == 2) {
        if (match_str(argv->at(argv, 1), "-help") == 1)
            display_help();
        return 1;
    }
    else if (argv->size(argv) == 3) {
        if (check_argv_p2(argv) == 84)
            return 84;
    }
    return 0;
}

int main(int argc, char **argv)
{
    client_t *client;
    lklist_str_t *av = lklist_str_init(NULL);
    int r = 0;

    for (int i = 0; i != argc; i += 1)
        av->push_back(av, lklist_char_init(argv[i]));
    r = check_argv(av);
    if (r == 84)
        return r;
    if (r == 1)
        return 0;
    client = init_client_connection(av->at(av, 1), av->at(av, 2));
    return start_client(client);
}