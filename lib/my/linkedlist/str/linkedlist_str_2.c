/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019
** File description:
** linkedlist_str_2
*/

#include "func_linkedlist.h"

lklist_char_t *lklist_str_at(lklist_str_t *ll, size_t index)
{
    size_t len = lklist_str_size(ll);
    lklist_str_t *begin = NULL;

    if (ll == NULL || index >= len) {
        fprintf(stderr,
        "error in lklist_str_at(): index is out of range\n");
        exit(84);
    }
    begin = ll;
    for (size_t i = 0; i != index; begin = begin->_next, i += 1);
    return begin->_elem;
}

void lklist_str_erase_n(lklist_str_t *ll, size_t index)
{
    lklist_str_t *tmp = NULL;
    lklist_str_t *tmp2 = NULL;
    lklist_str_t *begin = NULL;

    begin = ll;
    for (size_t i = 0; i != index; begin = begin->_next, i += 1);
    tmp2 = begin->_prev;
    tmp = begin->_next;
    free(begin);
    tmp2->_next = tmp;
    if (tmp2->_next != NULL)
        tmp2->_next->_prev = tmp2;
}

void lklist_str_erase_zero(lklist_str_t *ll)
{
    lklist_str_t *tmp = NULL;

    if (ll->_next == NULL) {
        ll->_elem = NULL;
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

void lklist_str_erase(lklist_str_t *ll, size_t index)
{
    size_t len = lklist_str_size(ll);

    if (ll == NULL || index >= len) {
        fprintf(stderr, "error in lklist_str_pop_back():");
        fprintf(stderr, " index is out of range\n");
        exit(84);
    }
    if (index == 0)
        lklist_str_erase_zero(ll);
    else if (index > 0)
        lklist_str_erase_n(ll, index);
    ll->size -= 1;
    return;
}

void lklist_str_clear(lklist_str_t *ll)
{
    size_t len = 0;

    if (lklist_str_size(ll) == 0)
        return;
    len = lklist_str_size(ll) - 1;
    for (; len != 0; len -= 1)
        lklist_str_pop_back(ll);
    lklist_str_pop_back(ll);
    return;
}