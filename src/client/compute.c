/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019
** File description:
** compute
*/

#include "client.h"
#include "command_cli.h"

int compute_get_answ_addinfos_login(lklist_str_t *pr)
{
    lklist_str_t *answ_sec = parse_str2lklist(pr->at(pr, 1), ' ');
    char *uuid = answ_sec->at(answ_sec, 0)->to_str(answ_sec->at(answ_sec, 0));
    char *name = answ_sec->at(answ_sec, 1)->to_str(answ_sec->at(answ_sec, 1));

    client_event_loggedin(uuid, name);
    free(uuid);
    free(name);
    return 0;
}

int compute_get_answ_addinfos(lklist_str_t *pr)
{
    if (match_str(pr->at(pr, 0), keycodes.user_connected) == 1)
        compute_get_answ_addinfos_login(pr);
    if (match_str(pr->at(pr, 0), keycodes.user_disconnected) == 1)
        compute_get_answ_addinfos_logout(pr);
}

int compute_get_answ_serv(client_t *client)
{
    lklist_char_t *r = NULL;
    lklist_str_t *pr = NULL;

    if (client->command_status == 0) {
        r = read_fd(client->network->sockfd);
        pr = get_answ_server(r);
        if (pr == NULL || pr->size(pr) == 0)
            return 0;
        compute_get_answ_addinfos(pr);
        return 0;
    }
    client->command[client->curr_func](client);
    client->command_status = 0;
    client->curr_func = 0;
}

int send_command_next(client_t *client, int check)
{
    for (size_t i = 0; client->command[i] != NULL; i += 1) {
        check = client->command[i](client);
        if (check == 1) {
            client->command_status = 1;
            client->curr_func = i;
            break;
        }
    }
    if (check == 0)
        printf("%s\n", "Command failed: Unknown command");
    free_command(client);
    return 0;
}

int send_command(client_t *client)
{
    int check = 0;

    if (client->command_status == 1)
        client->command_status = 0;
    client->client_answer = read_fd(STDIN);
    if (client->client_answer == NULL) {
        printf("%s\n", "Command failed: Unknown command");
        return 0;
    }
    client->client_answer_p = parse_command(client->client_answer);
    if (client->client_answer_p == NULL) {
        printf("%s\n", "Command failed: Unknown command");
        return 0;
    }
    return send_command_next(client, check);
}