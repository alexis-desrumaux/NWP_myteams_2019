/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019
** File description:
** display_help
*/

#include "server.h"

void display_help(void)
{
    my_printf("USAGE: ./myteams_server port\n\n");
    my_printf("       port  is the port number");
    my_printf(" on which the server socket listens.\n");
    return;
}