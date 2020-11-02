/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019
** File description:
** linkedlist_char
*/

#include "func_linkedlist.h"

void lklist_char_pop_back(lklist_char_t *ll)
{
    lklist_char_t *begin = NULL;

    if (ll == NULL) {
        fprintf(stderr, "error in lklist_char_pop_back(): ll == NULL\n");
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

void lklist_char_push_back(lklist_char_t *ll, char c)
{
    lklist_char_t *begin = NULL;

    if (ll == NULL) {
        fprintf(stderr, "error in lklist_char_push_back(): ll == NULL\n");
        exit(84);
    }
    if (ll != NULL && ll->_size == 0) {
        ll->_elem = c;
        ll->_size += 1;
        return;
    }
    for (begin = ll; begin->_next != NULL; begin = begin->_next);
    begin->_next = malloc(sizeof(lklist_char_t));
    begin->_next->_prev = begin;
    begin->_next->_next = NULL;
    begin->_next->_elem = c;
    ll->_size += 1;
    return;
}

void lklist_char_init_func(lklist_char_t *ll)
{
    ll->at = lklist_char_at;
    ll->clear = lklist_char_clear;
    ll->erase = lklist_char_erase;
    ll->pop_back = lklist_char_pop_back;
    ll->push_back = lklist_char_push_back;
    ll->size = lklist_char_size;
    ll->insert = lklist_char_insert;
    ll->fill = lklist_char_cfill;
    ll->lkl_fill = lklist_char_lklfill;
    ll->set = lklist_char_set;
    ll->to_str = lklist_char_to_str;
    ll->free = lklist_char_free;
}

lklist_char_t *lklist_char_lklinit(lklist_char_t *str)
{
    lklist_char_t *ll = lklist_char_init(NULL);

    ll->lkl_fill(ll, str);
    return ll;
}

lklist_char_t *lklist_char_init(char *str)
{
    lklist_char_t *ll = malloc(sizeof(lklist_char_t));

    ll->_elem = '\0';
    ll->_next = NULL;
    ll->_prev = NULL;
    ll->_size = 0;
    lklist_char_init_func(ll);
    if (str != NULL)
        lklist_char_cfill(ll, str);
    return ll;
}
