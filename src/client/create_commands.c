/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019
** File description:
** create_commands
*/

#include "client.h"
#include "command_cli.h"

void create_commands(client_t *client)
{
    client->command[0] = login;
    client->command[1] = users;
    client->command[2] = user;
    client->command[3] = c_send;
    client->command[4] = c_logout;
    client->command[5] = NULL;
    return;
}