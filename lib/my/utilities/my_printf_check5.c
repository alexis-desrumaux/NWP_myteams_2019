/*
** EPITECH PROJECT, 2018
** my_printf_check5.c
** File description:
** check5
*/

#include "mylib.h"
#include <stdarg.h>
#include <unistd.h>

void f_check5(int check, va_list va, char *spe, int i)
{
    int arg4;

    if (check == 5) {
        arg4 = va_arg(va, int);
        my_putnbr(arg4);
        f_dispflag_printf(spe, 3, i+2);
    }
    else if (check != 5)
    f_check6(check, va, spe, i);
}
