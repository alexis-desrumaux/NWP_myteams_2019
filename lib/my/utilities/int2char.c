/*
** EPITECH PROJECT, 2018
** Lib
** File description:
** int2char.c
*/

#include <stdlib.h>
#include <stdio.h>
#include "mylib.h"

lklist_char_t *case_neg_int2char(lklist_char_t *str)
{
    int j = 0;
    lklist_char_t *strneg = lklist_char_init(NULL);

    if (strneg == NULL)
        return NULL;
    strneg->push_back(strneg, '-');
    while (j != (int)str->size(str)) {
        strneg->push_back(strneg, str->at(str, j));
        j += 1;
    }
    return strneg;
}

int compteurdizaine2(int nb)
{
    int i = 0;
    int j = 1;
    int obj = 100;

    while (i != nb) {
        if (i == 10)
            j++;
        if (i == obj && j != obj) {
            obj = obj * 10;
            j++;
        }
        i++;
    }
    if (nb == 100)
        j = 3;
    if (nb == 10)
        j = 2;
    return (j);
}

lklist_char_t *int2char_part2(lklist_char_t *str,
int nb, int check)
{
    int i = 0;
    int nb2;
    int nb3;
    int nbdizaine;

    nbdizaine = compteurdizaine2(nb);
    for (; i != nbdizaine - 1; i++) {
        nb2 = nb / f_puiss(10, nbdizaine - i - 1);
        str->push_back(str, nb2 + 48);
        nb3 = nb - nb2 * f_puiss(10, nbdizaine - i - 1);
        nb = nb3;
    }
    str->push_back(str, nb + 48);
    if (check == 1)
        str = case_neg_int2char(str);
    if (str == NULL)
        return NULL;
    return str;
}

lklist_char_t *int2char(int nb)
{
    int check = 0;
    lklist_char_t *str = lklist_char_init(NULL);

    if (nb < 0) {
        nb = nb * (-1);
        check = 1;
    }
    return int2char_part2(str, nb, check);
}