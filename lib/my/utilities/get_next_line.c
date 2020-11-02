/*
** EPITECH PROJECT, 2018
** CPE_getnextline_2018
** File description:
** get_next_line.c
*/

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "mylib.h"
#include <unistd.h>

char *my_strcpy2(char *strdest, char *str)
{
    int i = 0;

    while (str[i] != '\0') {
        strdest[i] = str[i];
        i++;
    }
    strdest[i] = '\0';
    return (strdest);
}

char *realloc_nextline(char *str1, char *str2, int *tableau)
{
    tableau[5] += 200;
    str2 = malloc(tableau[5]);
    str2 = my_strcpy2(str2, str1);
    return (str2);
}

char *get_next_line_part2(char *str, int sav_i, int check2, char *str2)
{
    free(str2);
    str[sav_i] = '\0';
    if (check2 != 2)
        return (str);
    else if (check2 == 2)
        return (NULL);
    return NULL;
}

char *get_next_line(int fd)
{
    int tableau[6] = {0, 0, 0, 0, 0, 200};
    char *str = malloc(tableau[5]);
    char *str2 = malloc(tableau[5]);

    while (tableau[2] != 1) {
        read(fd, str + tableau[0], 1);
        if (str[tableau[0]] == '\n') {
            tableau[2] = 1;
            tableau[4] = tableau[0];
        } else if (str[tableau[0]] == 0) {
            tableau[3] = 2;
            tableau[2] = 1;
        } if (tableau[1] == 199) {
            str = realloc_nextline(str, str2, tableau);
            tableau [1] = -1;
        }
        tableau[1]++;
        tableau[0]++;
    }
    return (get_next_line_part2(str, tableau[4], tableau[3], str2));
}
