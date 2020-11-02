/*
** EPITECH PROJECT, 2018
** my_strlen.c
** File description:
** my_strlen function
*/

#include "mylib.h"

int my_strlen(char *str)
{
    int position = 0;
    int longueur = 0;

    while (str[position] != '\0') {
        longueur++;
        position++;
    }
    return (longueur);
}
