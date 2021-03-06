/*
** EPITECH PROJECT, 2018
** my_putnbr_long.c
** File description:
** my_putnbr function with a long value
*/

#include "mylib.h"

void my_putnbr_short(short nb)
{
    short modulo;
    modulo = 0;

    if (nb <= 9 && nb >= 0)
    my_putchar(nb + '0');
    if (nb < 0)
    {
        my_putchar('-');
        nb = nb * (- 1);
    if (nb <= 9 && nb >= 0)
        my_putnbr_short(nb);
    }
    if (nb > 9) {
        modulo = nb % 10;
        my_putnbr_short(nb / 10);
        my_putchar(modulo + '0');
    }
}
