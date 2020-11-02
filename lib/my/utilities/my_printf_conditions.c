/*
** EPITECH PROJECT, 2018
** my_printf_conditions
** File description:
** conditions check
*/

#include "mylib.h"

int f_my_printfcond3(char *spe, int i, int check)
{
    if (spe[i+1] == 108 && spe[i+2] == 100)
    check = 6;
    else if (spe[i+1] == 104 && spe[i+2] == 100)
    check = 7;
    return (check);
}

int f_my_printfcond2(char *spe, int i, int check)
{
    if (spe[i+1] == 99)
    check = 4;
    else if (spe[i+1] == 112)
    check = 5;
    check = f_my_printfcond3(spe, i, check);
    return (check);
}

int f_my_printfcond(char *spe, int i)
{
    int check = 0;
    int retour = 0;

    if (spe[i] == 37) {
        if (spe[i+1] == 115 || spe[i+1] == 83)
        check = 1;
        else if (spe[i+1] == 100)
        check = 2;
        check = f_my_printfcond2(spe, i, check);
    }
    else {
        retour = f_carriage(spe, i);
        return (retour);
    }
    return (check);
}
