/*
** EPITECH PROJECT, 2018
** Lib
** File description:
** my_f_puiss.c
*/

#include "mylib.h"

int f_puiss(int nb, int puiss)
{
    int i = 1;
    int coef = nb;

    while (i != puiss) {
        nb = coef * nb;
        i++;
    }
    return (nb);
}
