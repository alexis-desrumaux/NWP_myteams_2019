/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019
** File description:
** linkedlist_int_3
*/

#include "func_linkedlist.h"

void lklist_int_insert_n(lklist_int_t *ll, size_t index, int nb)
{
    lklist_int_t *current = ll;
    lklist_int_t *new_st = lklist_int_init();
    size_t i = 0;

    for (; i != index; i += 1, current = current->_next);
    new_st->_elem = current->_elem;
    new_st->_next = current->_next;
    new_st->_prev = current;
    current->_elem = nb;
    current->_next = new_st;
    return;
}

void lklist_int_insert_zero(lklist_int_t *ll, int nb)
{
    lklist_int_t *one = lklist_int_init();

    one->_elem = ll->_elem;
    one->_next = ll->_next;
    one->_prev = ll;
    ll->_elem = nb;
    ll->_next = one;
    return;
}

void lklist_int_insert(lklist_int_t *ll, size_t index, int nb)
{
    size_t len = lklist_int_size(ll);

    if (ll == NULL || index > len) {
        fprintf(stderr, "error in lklist_int_insert():");
        fprintf(stderr, " index is out of range\n");
        exit(84);
    }
    if (index == len) {
        lklist_int_push_back(ll, nb);
        return;
    }
    if (index == 0)
        lklist_int_insert_zero(ll, nb);
    else if (index > 0)
        lklist_int_insert_n(ll, index, nb);
    ll->_size += 1;
    return;
}