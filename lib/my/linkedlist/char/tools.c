/*
** EPITECH PROJECT, 2020
** tools.c
** File description:
** tools
*/

#include "linkedlist.h"

char *cv_lklist_to_nstring(lklist_char_t *list)
{
    char *str = cpy_lklist_to_nstring(list);

    list->clear(list);
    free(list);
    return str;
}

char *cpy_lklist_to_nstring(lklist_char_t *list)
{
    char *str = NULL;
    size_t i = 0;

    if (list->size(list) == 0)
        return NULL;
    str = malloc(sizeof(char) * (list->size(list) + 1));
    for (; i != list->size(list); i += 1)
        str[i] = list->at(list, i);
    str[i] = '\0';
    return str;
}

lklist_char_t *cv_string_to_nlklist(char *str)
{
    lklist_char_t *new = lklist_char_init(NULL);

    for (size_t i = 0; str[i] != '\0'; i += 1)
        new->push_back(new, str[i]);
    free(str);
    return new;
}

lklist_char_t *cpy_string_to_nlklist(char *str)
{
    lklist_char_t *new = lklist_char_init(NULL);

    for (size_t i = 0; str[i] != '\0'; i += 1)
        new->push_back(new, str[i]);
    return new;
}