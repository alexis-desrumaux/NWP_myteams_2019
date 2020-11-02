/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019
** File description:
** tools
*/

#include "server.h"

char *lklist_to_string(lklist_char_t *list)
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

void string_to_lklist(char *str, lklist_char_t *list)
{
    for (size_t i = 0; str[i] != '\0'; i += 1)
        list->push_back(list, str[i]);
    return;
}