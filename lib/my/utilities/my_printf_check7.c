/*
** EPITECH PROJECT, 2018
** my_printf_check7.c
** File description:
** check7
*/

#include "mylib.h"
#include <stdarg.h>
#include <unistd.h>

void f_check7(int check, va_list va, char *spe, int i)
{
    short arg6;

    if (check == 7) {
        arg6 = va_arg(va, int);
        my_putnbr_short(arg6);
        f_dispflag_printf(spe, 3, i+3);
    }
    else if (check == -1)
    my_putchar('\n');
}
