/*
** EPITECH PROJECT, 2019
** ALEXIS DESRUMAUX
** File description:
** file.c
*/

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include "mylib.h"

lklist_char_t *catch_str_ij(int i, lklist_char_t *origin, int j)
{
    lklist_char_t *str = lklist_char_init(NULL);
    int k = 0;

    if (!str)
        return NULL;
    for (; i != j && i != (int)origin->size(origin); i++, k++)
        str->push_back(str, origin->at(origin, i));
    return str;
}

lklist_char_t *catch_str(int i, char symbol,
lklist_char_t *origin, char symbol2)
{
    lklist_char_t *str = lklist_char_init(NULL);
    int k = 0;

    if (symbol != '\0') {
        for (; origin->at(origin, i) != symbol &&
        i != (int)origin->size(origin); i += 1);
        i++;
    }
    for (; i != (int)origin->size(origin) && origin->at(origin, i) != symbol2 &&
    i != (int)origin->size(origin); i++, k++)
        str->push_back(str, origin->at(origin, i));
    return str;
}

int catch_str_int(int i, char symbol,
lklist_char_t *origin, char symbol2)
{
    lklist_char_t *str = NULL;
    int nb = 0;

    str = catch_str(i, symbol, origin, symbol2);
    if (!str)
        return -1;
    nb  = my_putint(str);
    str->free(str);
    return nb;
}