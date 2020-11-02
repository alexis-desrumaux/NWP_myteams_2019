/*
** EPITECH PROJECT, 2018
** my_printf_check3.c
** File description:
** check3
*/

#include "mylib.h"
#include <stdarg.h>
#include <unistd.h>

void f_check3(int check, va_list va, char *spe, int i)
{
    if (check == 3) {
    }
    else if (check != 3)
    f_check4(check, va, spe, i);
}
