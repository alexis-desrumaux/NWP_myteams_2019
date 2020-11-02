/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019
** File description:
** user2
*/

#include "mylib.h"
#include "command_cli.h"

void c_user_free_str(lklist_char_t *r, lklist_str_t *p_r)
{
    r->free(r);
    for (size_t i = 0; i != p_r->size(p_r); i += 1)
        p_r->at(p_r, i)->free(p_r->at(p_r, i));
    p_r->free(p_r);
}