/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019
** File description:
** linkedlist_str
*/

#include "func_linkedlist.h"

void lklist_str_pop_back(lklist_str_t *ll)
{
    lklist_str_t *begin = NULL;

    if (ll == NULL) {
        fprintf(stderr, "error in lklist_str_pop_back(): ll == NULL\n");
        exit(84);
    }
    if (ll->_size == 1) {
        ll->_elem = NULL;
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

void lklist_str_push_back(lklist_str_t *ll, lklist_char_t *str)
{
    lklist_str_t *begin = NULL;

    if (ll == NULL) {
        fprintf(stderr, "error in lklist_str_push_back(): ll == NULL\n");
        exit(84);
    }
    if (ll != NULL && ll->_size == 0) {
        ll->_elem = str;
        ll->_size += 1;
        return;
    }
    for (begin = ll; begin->_next != NULL; begin = begin->_next);
    begin->_next = malloc(sizeof(lklist_str_t));
    begin->_next->_prev = begin;
    begin->_next->_next = NULL;
    begin->_next->_elem = str;
    ll->_size += 1;
    return;
}

void lklist_str_init_func(lklist_str_t *ll)
{
    ll->at = lklist_str_at;
    ll->clear = lklist_str_clear;
    ll->erase = lklist_str_erase;
    ll->pop_back = lklist_str_pop_back;
    ll->push_back = lklist_str_push_back;
    ll->size = lklist_str_size;
    ll->insert = lklist_str_insert;
    ll->fill = lklist_str_strfill;
    ll->lkl_fill = lklist_str_lklfill;
    ll->set = lklist_str_set;
    ll->free = lklist_str_free;
}

lklist_str_t *lklist_str_lklinit(lklist_str_t *new)
{
    lklist_str_t *ll = lklist_str_init(NULL);

    lklist_str_lklfill(ll, new);
    return ll;
}

lklist_str_t *lklist_str_init(char **array)
{
    lklist_str_t *ll = malloc(sizeof(lklist_str_t));

    ll->_elem = NULL;
    ll->_next = NULL;
    ll->_prev = NULL;
    ll->_size = 0;
    lklist_str_init_func(ll);
    if (array != NULL)
        lklist_str_strfill(ll, array);
    return ll;
}
