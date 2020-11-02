/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019
** File description:
** linkedlist_char_2
*/

#include "func_linkedlist.h"

void lklist_char_erase_n(lklist_char_t *ll, size_t index)
{
    lklist_char_t *tmp = NULL;
    lklist_char_t *tmp2 = NULL;
    lklist_char_t *begin = NULL;

    begin = ll;
    for (size_t i = 0; i != index; begin = begin->_next, i += 1);
    tmp2 = begin->_prev;
    tmp = begin->_next;
    free(begin);
    tmp2->_next = tmp;
    if (tmp2->_next != NULL)
        tmp2->_next->_prev = tmp2;
}

void lklist_char_erase_zero(lklist_char_t *ll)
{
    lklist_char_t *tmp = NULL;

    if (ll->_next == NULL) {
        ll->_elem = '\0';
    }
    else if (ll->_next != NULL) {
        ll->_elem = ll->_next->_elem;
        tmp = ll->_next->_next;
        free(ll->_next);
        ll->_next = tmp;
        if (ll->_next != NULL)
            ll->_next->_prev = ll;
    }
}

void lklist_char_erase(lklist_char_t *ll, size_t index)
{
    size_t len = lklist_char_size(ll);

    if (ll == NULL || index >= len) {
        fprintf(stderr, "error in lklist_char_pop_back():");
        fprintf(stderr, " index is out of range\n");
        exit(84);
    }
    if (index == 0)
        lklist_char_erase_zero(ll);
    else if (index > 0)
        lklist_char_erase_n(ll, index);
    ll->_size -= 1;
    return;
}

void lklist_char_clear(lklist_char_t *ll)
{
    size_t len = 0;

    if (lklist_char_size(ll) == 0)
        return;
    len = lklist_char_size(ll) - 1;
    for (; len != 0; len -= 1)
        lklist_char_pop_back(ll);
    lklist_char_pop_back(ll);
    return;
}

char lklist_char_at(lklist_char_t *ll, size_t index)
{
    size_t len = lklist_char_size(ll);
    lklist_char_t *begin = NULL;

    if (ll == NULL || index >= len) {
        fprintf(stderr,
        "error in lklist_char_at(): index is out of range\n");
        exit(84);
    }
    begin = ll;
    for (size_t i = 0; i != index; begin = begin->_next, i += 1);
    return begin->_elem;
}