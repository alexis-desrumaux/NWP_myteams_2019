/*
** EPITECH PROJECT, 2018
** Lib
** File description:
** my_strcpy.c
*/

#include "mylib.h"

char *my_strcpy(char *strdest, char *str)
{
    int i = 0;

    while (str[i] != '\0') {
        strdest[i] = str[i];
        i++;
    }
    strdest[i] = '\0';
    return (strdest);
}
