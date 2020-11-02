/*
** EPITECH PROJECT, 2020
** NWP_myftp_2019
** File description:
** watchers
*/

#include "server.h"

int accept_client(int sockfd, struct sockaddr_in *cli)
{
    int connfd = 0;
    socklen_t len = sizeof(*cli);

    connfd = accept(sockfd, (SA*)&*cli, &len);
    if (connfd < 0) {
        printf("[EPITECH TEAMS] Server acccept failed...\n");
        exit(0);
    }
    else {
        printf("[EPITECH TEAMS] Server acccept the");
        printf(" client with IP: ");
        printf("%s PORT: %d\n", inet_ntoa(cli->sin_addr),
        ntohs(cli->sin_port));
    }
    return connfd;
}

int watch_a_client(server_t *server, lklist_char_t *buff,
lklist_int_t *cli_d, int i)
{
    buff = read_fd(((client_t *)
    server->clients->at(server->clients, i))->socket);
    if (buff->size(buff) == 0)
        return 0;
    if (match_str(buff, "^C") == 1 || match_str(buff, "/logout") == 1)
        cli_d->push_back(cli_d, i);
    compute(server,(client_t *)server->clients
    ->at(server->clients, i), buff);
    return 1;
}

int watch_clients(server_t *server)
{
    lklist_char_t *buff = NULL;
    lklist_int_t *cli_d = lklist_int_init();
    int check = 0;

    for (int i = (int)server->clients->size(server->clients) - 1;
    server->clients->size(server->clients) != 0
    && i != -1; i -= 1) {
        if (FD_ISSET(((client_t *)server->clients->at
        (server->clients, i))->socket, &server->network->rdfs)) {
            check = watch_a_client(server, buff, cli_d, i);
            if (check == 0)
                continue;
        }
    }
    for (int i = (int)cli_d->size(cli_d) - 1; i != -1; i -= 1) {
        close_socket_connection(server, cli_d->at(cli_d, i));
        cli_d->erase(cli_d, i);
    }
    return 0;
}

int watch_socket(server_t *server)
{
    client_t *new_client = NULL;

    if (FD_ISSET(server->network->sockfd, &server->network->rdfs)) {
        server->network->new_cli = malloc(sizeof(struct sockaddr_in));
        server->network->new_csock =
        accept_client(server->network->sockfd,
        server->network->new_cli);
        server->network->max = server->network->new_csock >
        server->network->max ? server->network->new_csock :
        server->network->max;
        new_client = malloc(sizeof(client_t));
        new_client->socket = server->network->new_csock;
        new_client->info = server->network->new_cli;
        new_client->logged = 0;
        server->clients->push_back(server->clients, new_client, "client_t *");
        dprintf(new_client->socket, "%s\n", "[0] SUCCESSFULY CONNECTED !");
    }
    return 0;
}