/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019
** File description:
** login
*/

#include "mylib.h"
#include "command_cli.h"

void print_event(client_t *client, lklist_str_t *all_answ)
{
    char *uuid = NULL;
    char *name = NULL;
    lklist_char_t *answ = NULL;
    lklist_str_t *p_answ = NULL;

    answ = lklist_char_lklinit(all_answ->at(all_answ, 1));
    p_answ = parse_str2lklist(answ, ';');
    uuid = p_answ->at(p_answ, 0)->to_str(p_answ->at(p_answ, 0));
    name = p_answ->at(p_answ, 1)->to_str(p_answ->at(p_answ, 1));
    client_event_loggedin(uuid, name);
    free_response(uuid, name, answ, p_answ);
}

void l_check_key(client_t *client, lklist_str_t *pansw)
{
    if (pansw != NULL) {
        if (match_str(pansw->at(pansw, 0), keycodes.invalid) == 1)
            printf("%s\n", "Command failed: Unknown command");
        else if (match_str(pansw->at(pansw, 0), keycodes.valid_w_r) == 1)
            print_event(client, pansw);
        else if (match_str(pansw->at(pansw, 0), keycodes.already_exist) == 1)
            client_error_already_exist();
    }
}

int c_login_read_fd(client_t *client)
{
    lklist_char_t *answ = NULL;
    lklist_str_t *pansw = NULL;

    answ = read_fd(client->network->sockfd);
    if (answ == NULL || answ->size(answ) == 0)
        return 1;
    pansw = get_answ_server(answ);
    answ->free(answ);
    if (pansw != NULL) {
        l_check_key(client, pansw);
        for (size_t i = 0; i != pansw->size(pansw);
        pansw->at(pansw, i)->free(pansw->at(pansw, i)), i += 1);
        pansw->free(pansw);
    }
    return 1;
}

int c_cli_login_send_command(client_t *client)
{
    lklist_str_t *pbuff = client->client_answer_p;
    char *csend = client->client_answer->to_str(client->client_answer);
    lklist_char_t *answ = NULL;
    lklist_char_t *key = NULL;

    if (pbuff->size(pbuff) >= 1) {
        if (match_str(pbuff->at(pbuff, 0), "/login") == 1) {
            dprintf(client->network->sockfd, "%s\n", csend);
            free(csend);
            return 1;
        }
    }
    free(csend);
    return 0;
}

int login(client_t *client)
{
    if (client->command_status == 0)
        return c_cli_login_send_command(client);
    else if (client->command_status == 1)
        return c_login_read_fd(client);
    return 0;
}