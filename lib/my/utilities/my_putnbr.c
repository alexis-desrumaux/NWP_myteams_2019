/*
** EPITECH PROJECT, 2018
** my_putnbr.c
** File description:
** my_putnbr function
*/

#include "mylib.h"

void my_putnbr(int nb)
{
    int modulo;
    modulo = 0;

    if (nb <= 9 && nb >= 0)
    my_putchar(nb + '0');
    if (nb < 0)
    {
        my_putchar('-');
        nb = nb * (- 1);
    if (nb <= 9 && nb >= 0)
        my_putnbr(nb);
    }
    if (nb > 9) {
        modulo = nb % 10;
        my_putnbr(nb / 10);
        my_putchar(modulo + '0');
    }
}
