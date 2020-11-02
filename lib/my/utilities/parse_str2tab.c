/*
** EPITECH PROJECT, 2020
** lib
** File description:
** parse_str2tab
*/

#include "mylib.h"
#include "linkedlist.h"

lklist_str_t *catch_arg_buff_cond(int i, lklist_str_t *tab,
lklist_char_t *buff, lklist_int_t *index)
{
    if (i == 0) {
        tab->push_back(tab,
        catch_str(0, '\0',
        buff, buff->at(buff, index->at(index, i))));
    }
    else {
        tab->push_back(tab, catch_str(index->at(index, i - 1) + 1,
        '\0', buff, buff->at(buff, index->at(index, i))));
    }
    return tab;
}

lklist_str_t *catch_arg_buff(lklist_int_t *index, lklist_char_t *buff)
{
    lklist_str_t *tab = lklist_str_init(NULL);
    size_t i = 0;

    if (index == NULL || index->size(index) == 0) {
        tab->push_back(tab, buff);
        return tab;
    }
    for (; i != index->size(index); i += 1) {
        catch_arg_buff_cond(i, tab, buff, index);
    }
    tab->push_back(tab,
    catch_str(index->at(index, i - 1) + 1, '\0', buff, '\0'));
    buff->free(buff);
    index->clear(index);
    free(index);
    return tab;
}

lklist_int_t *index_of_symbol(lklist_char_t *buff, char symbol)
{
    int nbspaces = 0;
    lklist_int_t *index;

    for (size_t i = 0; i != buff->size(buff); i += 1) {
        if (buff->at(buff, i) == symbol)
            nbspaces++;
    }
    if (nbspaces == 0)
        return NULL;
    index = lklist_int_init();
    for (size_t i = 0; i != buff->size(buff); i += 1) {
        if (buff->at(buff, i) == symbol)
            index->push_back(index, i);
    }
    return index;
}

lklist_char_t *parse_str2lklist_cond(size_t endsymbol, lklist_char_t *buff)
{
    lklist_char_t *buffcpy = NULL;

    if (endsymbol == buff->size(buff) - 1)
        buffcpy = catch_str(0, '\0', buff, '\0');
    else
        buffcpy = catch_str_ij(0, buff, endsymbol + 1);
    return buffcpy;
}

lklist_str_t *parse_str2lklist(lklist_char_t *buff, char symbol)
{
    size_t endsymbol = 0;
    lklist_char_t *buffcpy = NULL;
    lklist_int_t *indexof_symbol;
    lklist_str_t *t = NULL;

    if (buff != NULL && buff->size(buff) != 0) {
        for (endsymbol = buff->size(buff) - 1;
        buff->at(buff, endsymbol) == symbol; endsymbol--);
        buffcpy = parse_str2lklist_cond(endsymbol, buff);
    }
    else
        return NULL;
    indexof_symbol = index_of_symbol(buffcpy, symbol);
    t = catch_arg_buff(indexof_symbol, buffcpy);
    return t;
}