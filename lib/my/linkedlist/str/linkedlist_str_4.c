/*
** EPITECH PROJECT, 2020
** lib
** File description:
** linkedlist_str_4
*/

#include "func_linkedlist.h"

void lklist_str_free(lklist_str_t *ll)
{
    lklist_str_clear(ll);
    free(ll);
}

void lklist_str_lklfill(lklist_str_t *ll, lklist_str_t *new)
{
    lklist_str_clear(ll);
    for (size_t i = 0; i != new->size(new); i += 1)
        ll->push_back(ll, new->at(new, i));
    return;
}

void lklist_str_strfill(lklist_str_t *ll, char **array)
{
    lklist_str_clear(ll);
    for (size_t i = 0; array[i] != NULL; i += 1)
        ll->push_back(ll, lklist_char_init(array[i]));
    return;
}

void lklist_str_set(lklist_str_t *ll, size_t index, lklist_char_t *str)
{
    lklist_str_erase(ll, index);
    lklist_str_insert(ll, index, str);
    return;
}