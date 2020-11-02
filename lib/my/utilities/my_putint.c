/*
** EPITECH PROJECT, 2018
** my_putint.c
** File description:
** my_putint.c
*/

#include <stdlib.h>
#include "mylib.h"

long f_conversion(int check, lklist_char_t *str,
long value, long zero)
{
    size_t i = 0;

    while (i != str->size(str)) {
        value += (str->at(str, i) - 48) * zero;
        zero /= 10;
        i += 1;
    }
    value /= 10;
    if (check == 1)
        value = value * -1;
    return (value);
}

lklist_char_t *isneg(lklist_char_t *str)
{
    long i = 1;
    lklist_char_t *newstr = lklist_char_init(NULL);

    if (newstr == NULL)
        return (NULL);
    while (i != (int)str->size(str)) {
        newstr->push_back(newstr, str->at(str, i));
        i++;
    }
    return (newstr);
}

long my_putint(lklist_char_t *str)
{
    int value = 0;
    long zero = 1;
    long i = 0;
    int check = 0;

    if (str->at(str, 0) == '-') {
        str = isneg(str);
        if (str == NULL || str->size(str) == 0)
            return (-1);
        check = 1;
    }
    while (i != (int)str->size(str)) {
        zero *= 10;
        i++;
    }
    return (f_conversion(check, str, value, zero));
}
