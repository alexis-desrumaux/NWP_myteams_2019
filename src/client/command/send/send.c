/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019
** File description:
** send
*/

#include "mylib.h"
#include "command_cli.h"

void c_send_check_kcodes_next(client_t *client, lklist_str_t *p_r)
{
    char *next_r_str = NULL;

    if (match_str(p_r->at(p_r, 0), keycodes.invalid) == 1)
        printf("%s\n", "Command failed: Unknown command");
    if (match_str(p_r->at(p_r, 0), keycodes.too_long_body) == 1) {
        next_r_str = cv_lklist_to_nstring(read_fd(client->network->sockfd));
        printf("Command failed: Your message is too long ! %d > %d\n",
        my_strlen(next_r_str), MAX_BODY_LENGTH);
        free(next_r_str);
    }
    if (match_str(p_r->at(p_r, 0), keycodes.valid_no_r) == 1) {
        printf("Your message has been successfuly sent !\n");
    }
}

void c_send_check_kcodes(client_t *client, lklist_str_t *p_r)
{
    char *next_r_str = NULL;

    if (match_str(p_r->at(p_r, 0), keycodes.unauthorised) == 1)
        client_error_unauthorized();
    if (match_str(p_r->at(p_r, 0), keycodes.user_n_exist) == 1) {
        next_r_str = p_r->at(p_r, 1)->to_str(p_r->at(p_r, 1));
        client_error_unknown_user(next_r_str);
        free(next_r_str);
    }
    c_send_check_kcodes_next(client, p_r);
}

int c_send_get_r(client_t *client)
{
    lklist_char_t *r = NULL;
    lklist_str_t *p_r = NULL;

    r = read_fd(client->network->sockfd);
    if (r == NULL)
        return 1;
    p_r = get_answ_server(r);
    r->free(r);
    if (p_r != NULL && p_r->size(p_r) != 0) {
        c_send_check_kcodes(client, p_r);
        for (size_t i = 0; i != p_r->size(p_r); i += 1)
            p_r->at(p_r, i)->free(p_r->at(p_r, i));
        p_r->free(p_r);
    }
    return 1;
}

int c_cli_send_send_command(client_t *client)
{
    lklist_str_t *pbuff = client->client_answer_p;
    char *csend = client->client_answer->to_str(client->client_answer);

    if (pbuff->size(pbuff) != 0) {
        if (match_str(pbuff->at(pbuff, 0), "/send") == 1) {
            dprintf(client->network->sockfd, "%s\n", csend);
            free(csend);
            return 1;
        }
    }
    free(csend);
    return 0;
}

int c_send(client_t *client)
{
    if (client->command_status == 0)
        return c_cli_send_send_command(client);
    if (client->command_status == 1)
        return c_send_get_r(client);
    return 0;
}