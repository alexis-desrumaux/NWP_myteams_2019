/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019
** File description:
** logout
*/

#include "mylib.h"
#include "command_cli.h"

void c_cli_logout_check_kcodes(client_t *client, lklist_str_t *p_r)
{
    char *uuid = NULL;
    char *name = NULL;
    lklist_str_t *answ_sec = NULL;

    if (match_str(p_r->at(p_r, 0), keycodes.exit)) {
        if (p_r->size(p_r) == 2) {
            answ_sec = parse_str2lklist(p_r->at(p_r, 1), ' ');
            uuid = answ_sec->at(answ_sec, 0)->to_str(answ_sec->at(answ_sec, 0));
            name = answ_sec->at(answ_sec, 1)->to_str(answ_sec->at(answ_sec, 1));
            client_event_loggedout(uuid, name);
            free(uuid);
            free(name);
            for (size_t i = 0; i != answ_sec->size(answ_sec); i += 1)
                answ_sec->at(answ_sec, i)->free(answ_sec->at(answ_sec, i));
            answ_sec->free(answ_sec);
        }
        client->exit = true;
    }
}

int c_cli_logout_get_r(client_t *client)
{
    lklist_char_t *r = NULL;
    lklist_str_t *p_r = NULL;

    r = read_fd(client->network->sockfd);
    if (r == NULL)
        return 1;
    p_r = get_answ_server(r);
    r->free(r);
    if (p_r != NULL && p_r->size(p_r) != 0) {
        c_cli_logout_check_kcodes(client, p_r);
        for (size_t i = 0; i != p_r->size(p_r); i += 1)
            p_r->at(p_r, i)->free(p_r->at(p_r, i));
        p_r->free(p_r);
    }
    return 1;
}

int c_cli_logout_send_command(client_t *client)
{
    lklist_str_t *pbuff = client->client_answer_p;
    char *csend = client->client_answer->to_str(client->client_answer);

    if (pbuff->size(pbuff) != 0) {
        if (match_str(pbuff->at(pbuff, 0), "/logout") == 1) {
            dprintf(client->network->sockfd, "%s\n", csend);
            free(csend);
            return 1;
        }
    }
    free(csend);
    return 0;
}

int c_logout(client_t *client)
{
    if (client->command_status == 0)
        return c_cli_logout_send_command(client);
    if (client->command_status == 1)
        return c_cli_logout_get_r(client);
    return 0;
}