/*
** EPITECH PROJECT, 2018
** Lib
** File description:
** disp flag
*/

#include "mylib.h"
#include "stdio.h"

int f_dispflag_printf(char *spe, int check, int i)
{
    while (spe[i] != 37 && spe[i] != '\n') {
        if (spe[i] == '\0')
        return (0);
        my_putchar(spe[i]);
        i++;
    }
    return (check);
}
