/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019
** File description:
** clean_str
*/

#include "client.h"

void clean_str_middle(lklist_char_t *clean_str_v)
{
    size_t i = clean_str_v->size(clean_str_v) - 1;
    bool del = false;

    for (; 1; i -= 1) {
        if (clean_str_v->at(clean_str_v, i) == ' ' ||
        clean_str_v->at(clean_str_v, i) == '\t') {
            if (del == true) {
                clean_str_v->erase(clean_str_v, i);
            }
            del = true;
        }
        else if (clean_str_v->at(clean_str_v, i) != ' ' &&
        clean_str_v->at(clean_str_v, i) != '\t') {
            del = false;
        }
        if (i == 0)
            break;
    }
}

void clean_str_back(lklist_char_t *clean_str)
{
    size_t i = 0;

    i = clean_str->size(clean_str) - 1;
    for (; clean_str->at(clean_str, i) == ' ' ||
    clean_str->at(clean_str, i) == '\t'; i -= 1) {
        clean_str->erase(clean_str, i);
        if (i == 0)
            break;
    }
}

void clean_str_head(lklist_char_t *clean_str_v)
{
    size_t i = 0;

    for (; i != clean_str_v->size(clean_str_v) &&
    (clean_str_v->at(clean_str_v, i) == ' ' ||
    clean_str_v->at(clean_str_v, i) == '\t'); i += 1);
    if (i != 0)
        i--;
    for (; clean_str_v->at(clean_str_v, i) == ' ' ||
    clean_str_v->at(clean_str_v, i) == '\t'; i -= 1) {
        clean_str_v->erase(clean_str_v, i);
        if (i == 0)
            break;
    }
}

lklist_char_t *clean_str(lklist_char_t *str)
{
    lklist_char_t *clean_str_v = lklist_char_lklinit(str);

    clean_str_head(clean_str_v);
    clean_str_back(clean_str_v);
    clean_str_middle(clean_str_v);
    return clean_str_v;
}