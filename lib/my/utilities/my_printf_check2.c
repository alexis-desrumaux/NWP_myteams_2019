/*
** EPITECH PROJECT, 2018
** my_printf_check2.c
** File description:
** check2
*/

#include "mylib.h"
#include <stdarg.h>
#include <unistd.h>

void f_check2(int check, va_list va, char *spe, int i)
{
    int arg = 0;
    int j = 0;

    if (check == 2) {
        while (j != 1) {
            arg = va_arg(va, int);
            my_putnbr(arg);
            j++;
        }
        f_dispflag_printf(spe, 3, i+2);
    }
    else if (check != 2)
        f_check3(check, va, spe, i);
}
