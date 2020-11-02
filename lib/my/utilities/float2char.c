/*
** EPITECH PROJECT, 2018
** HUB
** File description:
** to_strarg_float.c
*/

#include "stdio.h"
#include "stdlib.h"
#include "mylib.h"

lklist_char_t *isneg_float2char(lklist_char_t *str)
{
    int i = 0;
    lklist_char_t *neg = lklist_char_init(NULL);

    if (neg == NULL)
        return NULL;
    neg->push_back(neg, '-');
    while (i != (int)str->size(str)) {
        neg->push_back(neg, str->at(str, i));
        i++;
    }
    return neg;
}

lklist_char_t *float2char_part3(lklist_char_t *str,
lklist_char_t *decimal, int check)
{
    int i = 0;

    str->push_back(str, '.');
    while (i != (int)decimal->size(decimal)) {
        str->push_back(str, decimal->at(decimal, i));
        i++;
    }
    if (check == 1)
        str = isneg_float2char(str);
    if (str == NULL)
        return NULL;
    return str;
}

lklist_char_t *to_decimale_float(lklist_char_t *str, lklist_char_t *op2)
{
    int i = 0;
    lklist_char_t *result = lklist_char_init(NULL);

    if (result == NULL)
        return NULL;
    i = (int)str->size(str) - my_putint(op2);
    while (i != (int)str->size(str)) {
        result->push_back(result, str->at(str, i));
        i++;
    }
    return result;
}

lklist_char_t *float2char_part2(lklist_char_t *op, float value, int check)
{
    int i = 0;
    int dec = 0;
    lklist_char_t *str = lklist_char_init(NULL);
    lklist_char_t *op2 = lklist_char_init(NULL);
    lklist_char_t *decimal = lklist_char_init(NULL);

    if (op2 == NULL || decimal == NULL)
        return NULL;
    for (; i < value; i++);
    i--;
    str = int2char(i);
    op2->push_back(op2, op->at(op, 2));
    dec = (int)value * f_puiss(10, my_putint(op2));
    decimal = int2char(dec);
    decimal = to_decimale_float(decimal, op2);
    str = float2char_part3(str, decimal, check);
    if (str == NULL)
        return NULL;
    return str;
}

lklist_char_t *float2char(lklist_char_t *op, float value)
{
    int check = 0;
    lklist_char_t *str = NULL;

    if (value < 0) {
        check = 1;
        value = value * -1;
    }
    str = float2char_part2(op, value, check);
    if (str == NULL)
        return NULL;
    return str;
}
