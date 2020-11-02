/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019
** File description:
** compute2
*/

#include "client.h"
#include "command_cli.h"

void free_command(client_t *client)
{
    lklist_char_t *tmp = NULL;

    client->client_answer->free(client->client_answer);
    if (client->client_answer_p == NULL)
        return;
    for (size_t i = 0; i !=
    client->client_answer_p->size(client->client_answer_p); i += 1) {
        tmp = client->client_answer_p->at(client->client_answer_p, i);
        tmp->free(tmp);
    }
    client->client_answer_p->free(client->client_answer_p);
}

int compute_get_answ_addinfos_logout(lklist_str_t *pr)
{
    lklist_str_t *answ_sec = parse_str2lklist(pr->at(pr, 1), ' ');
    char *uuid = answ_sec->at(answ_sec, 0)->to_str(answ_sec->at(answ_sec, 0));
    char *name = answ_sec->at(answ_sec, 1)->to_str(answ_sec->at(answ_sec, 1));

    client_event_loggedout(uuid, name);
    free(uuid);
    free(name);
    return 0;
}