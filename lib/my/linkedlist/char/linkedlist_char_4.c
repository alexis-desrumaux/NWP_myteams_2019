/*
** EPITECH PROJECT, 2020
** lib
** File description:
** linkedlist_char_4
*/

#include "func_linkedlist.h"

void lklist_char_free(lklist_char_t *ll)
{
    lklist_char_clear(ll);
    free(ll);
}

char *lklist_char_to_str(lklist_char_t *ll)
{
    char *str = NULL;
    size_t i = 0;

    if (ll->size(ll) == 0)
        return NULL;
    str = malloc(sizeof(char) * (ll->size(ll) + 1));
    for (; i != ll->size(ll); i += 1)
        str[i] = ll->at(ll, i);
    str[i] = '\0';
    return str;
}

void lklist_char_lklfill(lklist_char_t *ll, lklist_char_t *new)
{
    lklist_char_clear(ll);
    for (size_t i = 0; i != new->size(new); i += 1) {
        ll->push_back(ll, new->at(new, i));
    }
    return;
}

void lklist_char_cfill(lklist_char_t *ll, char *str)
{
    lklist_char_clear(ll);
    for (size_t i = 0; str[i] != '\0'; i += 1)
        ll->push_back(ll, str[i]);
    return;
}

void lklist_char_set(lklist_char_t *ll, size_t index, char c)
{
    lklist_char_erase(ll, index);
    lklist_char_insert(ll, index, c);
    return;
}