/*
** EPITECH PROJECT, 2018
** Lib
** File description:
** '\n' function
*/

#include "mylib.h"

int f_carriage(char *spe, int i)
{
    if (spe[i] != 37 && spe[i] == '\n')
        return (-1);
    else if (spe[i] != 37 && spe[i] != '\n')
        return (0);
    return (0);
}
