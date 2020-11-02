/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019
** File description:
** login2
*/

#include "mylib.h"
#include "command_cli.h"

void free_response(char *uuid, char *name, lklist_char_t *answ,
lklist_str_t *p_answ)
{
    free(uuid);
    free(name);
    answ->free(answ);
    for (size_t i = 0; i != p_answ->size(p_answ); i += 1)
        p_answ->at(p_answ, i)->free(p_answ->at(p_answ, i));
    p_answ->free(p_answ);
}