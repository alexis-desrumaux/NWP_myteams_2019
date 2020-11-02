/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019
** File description:
** linkedlist_str_3
*/

#include "func_linkedlist.h"

size_t lklist_str_size(lklist_str_t *ll)
{
    return ll->_size;
}

void lklist_str_insert_n(lklist_str_t *ll, size_t index, lklist_char_t *str)
{
    lklist_str_t *current = ll;
    lklist_str_t *new_st = lklist_str_init(NULL);
    size_t i = 0;

    for (; i != index; i += 1, current = current->_next);
    new_st->_elem = current->_elem;
    new_st->_next = current->_next;
    new_st->_prev = current;
    current->_elem = str;
    current->_next = new_st;
    return;
}

void lklist_str_insert_zero(lklist_str_t *ll, lklist_char_t *str)
{
    lklist_str_t *one = lklist_str_init(NULL);

    one->_elem = ll->_elem;
    one->_next = ll->_next;
    one->_prev = ll;
    ll->_elem = str;
    ll->_next = one;
    return;
}

void lklist_str_insert(lklist_str_t *ll, size_t index, lklist_char_t *str)
{
    size_t len = lklist_str_size(ll);

    if (ll == NULL || index > len) {
        fprintf(stderr, "error in lklist_str_insert():");
        fprintf(stderr, " index is out of range\n");
        exit(84);
    }
    if (index == len) {
        lklist_str_push_back(ll, str);
        return;
    }
    if (index == 0)
        lklist_str_insert_zero(ll, str);
    else if (index > 0)
        lklist_str_insert_n(ll, index, str);
    ll->size += 1;
    return;
}