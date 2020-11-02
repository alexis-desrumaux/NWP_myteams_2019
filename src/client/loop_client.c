/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019
** File description:
** loop_client
*/

#include "client.h"

int check_connection_to_server_free(client_t *client, lklist_char_t *tmp)
{
    client->server_answer->free(client->server_answer);
    for (size_t i = 0; i != client->server_answer_p->
    size(client->server_answer_p); i += 1) {
        tmp = client->server_answer_p->
        at(client->server_answer_p, i);
        tmp->free(tmp);
    }
    return 1;
}

int check_connection_to_server(client_t *client)
{
    lklist_char_t *tmp = NULL;

    client->server_answer = read_fd(client->network->sockfd);
    client->server_answer_p = parse_str2lklist(client->server_answer, ' ');
    if (client->server_answer_p != NULL &&
    client->server_answer_p->size(client->server_answer_p) != 0) {
        tmp = client->server_answer_p->at(client->server_answer_p, 0);
        if (match_str(tmp, "[0]"))
            printf("[EPITECH TEAMS] Client connected to the server\n");
        else {
            printf("[EPITECH TEAMS] Unable to connect to the server\n");
            close(client->network->sockfd);
            return 0;
        }
    }
    return check_connection_to_server_free(client, tmp);
}

int loop_client(client_t *client)
{
    if (check_connection_to_server(client) == 0)
        return 84;
    while (client->exit == false) {
        client->network->max = client->network->sockfd;
        FD_ZERO(&client->network->rdfs);
        FD_SET(client->network->sockfd, &client->network->rdfs);
        FD_SET(STDIN, &client->network->rdfs);
        client->network->max = STDIN > client->network->max ?
        STDIN : client->network->max;
        select(client->network->max + 1,
        &client->network->rdfs, NULL, NULL, NULL);
        if (FD_ISSET(STDIN, &client->network->rdfs)) {
            send_command(client);
        }
        if (FD_ISSET(client->network->sockfd, &client->network->rdfs)) {
            compute_get_answ_serv(client);
        }
    }
    return 0;
}

int start_client(client_t *client)
{
    int r = 0;

    r = loop_client(client);
    close(client->network->sockfd);
    return r;
}