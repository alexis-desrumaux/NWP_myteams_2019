/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019
** File description:
** users
*/

#include "mylib.h"
#include "command_cli.h"

void print_users(lklist_str_t *all_answ)
{
    lklist_str_t *pbuff = NULL;
    lklist_char_t *answ = NULL;
    lklist_char_t *line = NULL;

    answ = lklist_char_lklinit(all_answ->at(all_answ, 1));
    if (answ == NULL || answ->size(answ) == 0)
        return;
    if (answ->size(answ) == 1 && answ->at(answ, 0) == '-')
        return;
    pbuff = parse_str2lklist(answ, ';');
    if (pbuff == NULL || pbuff->size(pbuff) == 0)
        return;
    for (size_t i = 0; i != pbuff->size(pbuff); i += 1) {
        line = pbuff->at(pbuff, i);
        print_infos_users(line);
    }
    answ->free(answ);
    for (size_t i = 0; i != pbuff->size(pbuff); i += 1)
        pbuff->at(pbuff, i)->free(pbuff->at(pbuff, i));
    pbuff->free(pbuff);
}

void u_check_key(lklist_str_t *pansw)
{
    if (match_str(pansw->at(pansw, 0), keycodes.invalid) == 1)
        printf("%s\n", "Command failed: Unknown command");
    if (match_str(pansw->at(pansw, 0), keycodes.unauthorised) == 1)
        client_error_unauthorized();
    if (match_str(pansw->at(pansw, 0), keycodes.valid_w_r) == 1)
        print_users(pansw);
}

int c_cli_users_read_fd(client_t *client)
{
    lklist_char_t *answ = NULL;
    lklist_str_t *pansw = NULL;

    answ = read_fd(client->network->sockfd);
    if (answ == NULL || answ->size(answ) == 0)
        return 1;
    pansw = get_answ_server(answ);
    answ->free(answ);
    if (pansw != NULL) {
        u_check_key(pansw);
        for (size_t i = 0; i != pansw->size(pansw);
        pansw->at(pansw, i)->free(pansw->at(pansw, i)), i += 1);
        pansw->free(pansw);
    }
    return 1;
}

int c_cli_users_send_command(client_t *client)
{
    lklist_str_t *pbuff = client->client_answer_p;
    char *csend = client->client_answer->
    to_str(client->client_answer);
    lklist_char_t *answ = NULL;

    if (pbuff->size(pbuff) == 1) {
        if (match_str(pbuff->at(pbuff, 0), "/users") == 1) {
            dprintf(client->network->sockfd, "%s\n", csend);
            free(csend);
            return 1;
        }
    }
    free(csend);
    return 0;
}

int users(client_t *client)
{
    if (client->command_status == 0)
        return c_cli_users_send_command(client);
    else if (client->command_status == 1)
        return c_cli_users_read_fd(client);
    return 0;
}
