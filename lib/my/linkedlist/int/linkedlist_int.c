/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019
** File description:
** linkedlist_int
*/

#include "func_linkedlist.h"

size_t lklist_int_size(lklist_int_t *ll)
{
    return ll->_size;
}

int lklist_int_at(lklist_int_t *ll, size_t index)
{
    size_t len = lklist_int_size(ll);
    lklist_int_t *begin = NULL;

    if (ll == NULL || index >= len) {
        fprintf(stderr,
        "error in lklist_int_at(): index is out of range\n");
        exit(84);
    }
    begin = ll;
    for (size_t i = 0; i != index; begin = begin->_next, i += 1);
    return begin->_elem;
}

void lklist_int_pop_back(lklist_int_t *ll)
{
    lklist_int_t *begin = NULL;

    if (ll == NULL) {
        fprintf(stderr, "error in lklist_int_pop_back(): ll == NULL\n");
        exit(84);
    }
    if (ll->_size == 1) {
        ll->_elem = '\0';
        ll->_next = NULL;
        ll->_prev = NULL;
        ll->_size -= 1;
        return;
    }
    for (begin = ll; begin->_next->_next != NULL; begin = begin->_next);
    free(begin->_next);
    begin->_next = NULL;
    ll->_size -= 1;
    return;
}

void lklist_int_push_back(lklist_int_t *ll, int nb)
{
    lklist_int_t *begin = NULL;

    if (ll == NULL) {
        fprintf(stderr, "error in lklist_int_push_back(): ll == NULL\n");
        exit(84);
    }
    if (ll != NULL && ll->_size == 0) {
        ll->_elem = nb;
        ll->_size += 1;
        return;
    }
    for (begin = ll; begin->_next != NULL; begin = begin->_next);
    begin->_next = malloc(sizeof(lklist_int_t));
    begin->_next->_prev = begin;
    begin->_next->_next = NULL;
    begin->_next->_elem = nb;
    ll->_size += 1;
    return;
}

lklist_int_t *lklist_int_init(void)
{
    lklist_int_t *ll = malloc(sizeof(lklist_int_t));

    ll->_elem = '\0';
    ll->_next = NULL;
    ll->_prev = NULL;
    ll->_size = 0;
    ll->at = lklist_int_at;
    ll->clear = lklist_int_clear;
    ll->erase = lklist_int_erase;
    ll->pop_back = lklist_int_pop_back;
    ll->push_back = lklist_int_push_back;
    ll->size = lklist_int_size;
    return ll;
}
