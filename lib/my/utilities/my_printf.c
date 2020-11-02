/*
** EPITECH PROJECT, 2018
** my_printf.c
** File description:
** my_printf function
*/

#include <unistd.h>
#include "mylib.h"
#include <stdarg.h>

void my_printf(char *spe, ...)
{
    int i = 0;
    int check = 0;
    va_list va;
    va_start (va, spe);
    f_dispflag_printf(spe, 3, 0);
    while (spe[i] != '\0') {
        check = f_my_printfcond(spe, i);
        f_check1(check, va, spe, i);
        i++;
    }
    va_end (va);
}
