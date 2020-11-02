/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019
** File description:
** linkedlist3
*/

#include "func_linkedlist.h"

char *lklist_get_type(lklist_t *ll, size_t index)
{
    size_t len = lklist_size(ll);
    lklist_t *begin = NULL;

    if (ll == NULL || index >= len) {
        fprintf(stderr,
        "error in lklist_at(): index is out of range\n");
        exit(84);
    }
    begin = ll;
    for (size_t i = 0; i != index; begin = begin->_next, i += 1);
    return begin->_type;
}

void lklist_insert_n(lklist_t *ll, size_t index, void *elem, char *type)
{
    lklist_t *current = ll;
    lklist_t *new_st = lklist_init();
    size_t i = 0;

    for (; i != index; i += 1, current = current->_next);
    new_st->_elem = current->_elem;
    new_st->_type = current->_type;
    new_st->_next = current->_next;
    new_st->_prev = current;
    current->_elem = elem;
    current->_type = type;
    current->_next = new_st;
    return;
}

void lklist_insert_zero(lklist_t *ll, void *elem, char *type)
{
    lklist_t *one = lklist_init();

    one->_elem = ll->_elem;
    one->_type = ll->_type;
    one->_next = ll->_next;
    one->_prev = ll;
    ll->_elem = elem;
    ll->_type = type;
    ll->_next = one;
    return;
}

void lklist_insert(lklist_t *ll, size_t index, void *elem, char *type)
{
    size_t len = lklist_size(ll);

    if (ll == NULL || index > len) {
        fprintf(stderr, "error in lklist_insert(): index is out of range\n");
        exit(84);
    }
    if (index == len) {
        lklist_push_back(ll, elem, type);
        return;
    }
    if (index == 0)
        lklist_insert_zero(ll, elem, type);
    else if (index > 0)
        lklist_insert_n(ll, index, elem, type);
    ll->_size += 1;
    return;
}