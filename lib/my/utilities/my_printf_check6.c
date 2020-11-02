/*
** EPITECH PROJECT, 2018
** my_printf_check6.c
** File description:
** check6
*/

#include "mylib.h"
#include <stdarg.h>
#include <unistd.h>

void f_check6(int check, va_list va, char *spe, int i)
{
    long arg5;

    if (check == 6) {
        arg5 = va_arg(va, long);
        my_putnbr_long(arg5);
        f_dispflag_printf(spe, 3, i+3);
    }
    else if (check != 6)
        f_check7(check, va, spe, i);
}
