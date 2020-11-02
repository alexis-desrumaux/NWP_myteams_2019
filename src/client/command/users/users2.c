/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019
** File description:
** users2
*/

#include "mylib.h"
#include "command_cli.h"

void print_infos_users(lklist_char_t *line)
{
    lklist_str_t *pline = NULL;
    char *name = NULL;
    char *uuid = NULL;
    char *log = NULL;

    pline = parse_str2lklist(line, ' ');
    uuid = pline->at(pline, 0)->to_str(pline->at(pline, 0));
    name = pline->at(pline, 1)->to_str(pline->at(pline, 1));
    log = pline->at(pline, 2)->to_str(pline->at(pline, 2));
    client_print_users(uuid, name, atoi(log));
    for (size_t i = 0; i != pline->size(pline); i += 1)
        pline->at(pline, i)->free(pline->at(pline, i));
    pline->free(pline);
    free(uuid);
    free(name);
    free(log);
}