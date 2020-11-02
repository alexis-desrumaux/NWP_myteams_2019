/*
** EPITECH PROJECT, 2018
** my_printf_check4.c
** File description:
** check4
*/

#include "mylib.h"
#include <stdarg.h>
#include <unistd.h>

void f_check4(int check, va_list va, char *spe, int i)
{
    int arg3;

    if (check == 4) {
        arg3 = va_arg(va, int);
        my_putchar(arg3);
        f_dispflag_printf(spe, 3, i+2);
    }
    else if (check != 4)
    f_check5(check, va, spe, i);
}
