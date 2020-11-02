/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019
** File description:
** display_help
*/

#include "client.h"

void display_help(void)
{
    printf("USAGE: ./myteams_cli ip port\n");
    printf("       ip   is the server ip ");
    printf("address on which the server socket listens\n");
    printf("       port is the port number on which the ");
    printf("server socket listens\n");
}