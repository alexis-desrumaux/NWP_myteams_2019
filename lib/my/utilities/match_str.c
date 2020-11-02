/*
** EPITECH PROJECT, 2019
** PSU_navy_2018
** File description:
** match_str.c
*/

#include "mylib.h"

int match_str(lklist_char_t *src, char *match)
{
    if ((int)src->size(src) != my_strlen(match))
        return 0;
    for (int i = 0; i != (int)src->size(src); i++) {
        if (src->at(src, i) != match[i])
            return 0;
    }
    return 1;
}
