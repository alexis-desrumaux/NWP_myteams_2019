/*
** EPITECH PROJECT, 2018
** my_printf_check1.c
** File description:
** check1
*/

#include "mylib.h"
#include <stdarg.h>
#include <unistd.h>

void f_check1(int check, va_list va, char *spe, int i)
{
    char *arg2;
    int j = 0;

    if (check == 1) {
        while (j != 1) {
            arg2 = va_arg(va, char *);
            my_putstr(arg2);
            j++;
        }
        f_dispflag_printf(spe, 3, i+2);
    }
    else if (check != 1)
    f_check2(check, va, spe, i);
}
