/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019
** File description:
** linkedlist
*/

#include "func_linkedlist.h"

size_t lklist_size(lklist_t *ll)
{
    return ll->_size;
}

void *lklist_at(lklist_t *ll, size_t index)
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
    return begin->_elem;
}

void lklist_pop_back(lklist_t *ll)
{
    lklist_t *begin = NULL;

    if (ll == NULL) {
        fprintf(stderr, "error in lklist_pop_back(): ll == NULL\n");
        exit(84);
    }
    if (ll->_size == 1) {
        ll->_elem = NULL;
        ll->_type = NULL;
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

void lklist_push_back(lklist_t *ll, void *elem, char *type)
{
    lklist_t *begin = NULL;

    if (ll == NULL) {
        fprintf(stderr, "error in lklist_push_back(): ll == NULL\n");
        exit(84);
    }
    if (ll != NULL && ll->_size == 0) {
        ll->_elem = elem;
        ll->_type = type;
        ll->_size += 1;
        return;
    }
    for (begin = ll; begin->_next != NULL; begin = begin->_next);
    begin->_next = malloc(sizeof(lklist_t));
    begin->_next->_prev = begin;
    begin->_next->_next = NULL;
    begin->_next->_elem = elem;
    begin->_next->_type = type;
    ll->_size += 1;
    return;
}

lklist_t *lklist_init(void)
{
    lklist_t *ll = malloc(sizeof(lklist_t));

    ll->_elem = NULL;
    ll->_next = NULL;
    ll->_prev = NULL;
    ll->_type = NULL;
    ll->_size = 0;
    ll->at = lklist_at;
    ll->clear = lklist_clear;
    ll->erase = lklist_erase;
    ll->get_type = lklist_get_type;
    ll->insert = lklist_insert;
    ll->pop_back = lklist_pop_back;
    ll->push_back = lklist_push_back;
    ll->size = lklist_size;
    return ll;
}
