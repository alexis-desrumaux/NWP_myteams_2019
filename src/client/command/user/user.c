/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019
** File description:
** user
*/

#include "mylib.h"
#include "command_cli.h"

void c_user_print_infos(client_t *client, lklist_str_t *all_answ)
{
    lklist_char_t *r = lklist_char_lklinit(all_answ->at(all_answ, 1));
    lklist_str_t *p_r = NULL;
    char *uuid = NULL;
    char *name = NULL;
    char *log = NULL;

    if (r == NULL || r->size(r) == 0)
        return;
    p_r = parse_str2lklist(r, ' ');
    if (p_r == NULL || p_r->size(p_r) != 3)
        return;
    uuid = p_r->at(p_r, 0)->to_str(p_r->at(p_r, 0));
    name = p_r->at(p_r, 1)->to_str( p_r->at(p_r, 1));
    log = p_r->at(p_r, 2)->to_str(p_r->at(p_r, 2));
    client_print_user(uuid, name, atoi(log));
    free(uuid);
    free(name);
    free(log);
    c_user_free_str(r, p_r);
}

void c_user_check_kcodes(client_t *client, lklist_str_t *p_r)
{
    lklist_char_t *rs = NULL;
    char *uuid = NULL;

    if (match_str(p_r->at(p_r, 0), keycodes.invalid) == 1)
        printf("%s\n", "Command failed: Unknown command");
    if (match_str(p_r->at(p_r, 0), keycodes.unauthorised) == 1)
        client_error_unauthorized();
    if (match_str(p_r->at(p_r, 0), keycodes.user_n_exist) == 1) {
        rs = lklist_char_lklinit(p_r->at(p_r, 1));
        uuid = rs->to_str(rs);
        client_error_unknown_user(uuid);
        free(uuid);
        rs->free(rs);
    }
    if (match_str(p_r->at(p_r, 0), keycodes.valid_w_r) == 1)
        c_user_print_infos(client, p_r);
}

int c_user_get_r(client_t *client)
{
    lklist_char_t *r = NULL;
    lklist_str_t *p_r = NULL;

    r = read_fd(client->network->sockfd);
    if (r == NULL)
        return 1;
    p_r = get_answ_server(r);
    r->free(r);
    if (p_r != NULL && p_r->size(p_r) != 0) {
        c_user_check_kcodes(client, p_r);
        for (size_t i = 0; i != p_r->size(p_r); i += 1)
            p_r->at(p_r, i)->free(p_r->at(p_r, i));
        p_r->free(p_r);
    }
    return 1;
}

int c_cli_user_send_command(client_t *client)
{
    lklist_str_t *pbuff = client->client_answer_p;
    char *csend = client->client_answer->to_str(client->client_answer);

    if (pbuff->size(pbuff) != 0) {
        if (match_str(pbuff->at(pbuff, 0), "/user")) {
            dprintf(client->network->sockfd, "%s\n", csend);
            free(csend);
            return 1;
        }
    }
    free(csend);
    return 0;
}

int user(client_t *client)
{
    if (client->command_status == 0)
        return c_cli_user_send_command(client);
    if (client->command_status == 1)
        return c_user_get_r(client);
    return 0;
}