/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019
** File description:
** linkedlist_char_3
*/

#include "func_linkedlist.h"

size_t lklist_char_size(lklist_char_t *ll)
{
    return ll->_size;
}

void lklist_char_insert_n(lklist_char_t *ll, size_t index, char c)
{
    lklist_char_t *current = ll;
    lklist_char_t *new_st = lklist_char_init(NULL);
    size_t i = 0;

    for (; i != index; i += 1, current = current->_next);
    new_st->_elem = current->_elem;
    new_st->_next = current->_next;
    new_st->_prev = current;
    current->_elem = c;
    current->_next = new_st;
    return;
}

void lklist_char_insert_zero(lklist_char_t *ll, char c)
{
    lklist_char_t *one = lklist_char_init(NULL);

    one->_elem = ll->_elem;
    one->_next = ll->_next;
    one->_prev = ll;
    ll->_elem = c;
    ll->_next = one;
    return;
}

void lklist_char_insert(lklist_char_t *ll, size_t index, char c)
{
    size_t len = lklist_char_size(ll);

    if (ll == NULL || index > len) {
        fprintf(stderr, "error in lklist_char_insert():");
        fprintf(stderr, " index is out of range\n");
        exit(84);
    }
    if (index == len) {
        lklist_char_push_back(ll, c);
        return;
    }
    if (index == 0)
        lklist_char_insert_zero(ll, c);
    else if (index > 0)
        lklist_char_insert_n(ll, index, c);
    ll->_size += 1;
    return;
}