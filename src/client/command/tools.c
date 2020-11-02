/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019
** File description:
** tools
*/

#include "command.h"

lklist_str_t *get_answ_server_no_more_answ(lklist_char_t *buff)
{
    lklist_str_t *array = lklist_str_init(NULL);

    array->push_back(array, lklist_char_lklinit(buff));
    return array;
}

lklist_str_t *get_answ_server_f2(lklist_char_t *buff, size_t index)
{
    size_t a = 0;
    size_t b = 0;
    lklist_str_t *array = lklist_str_init(NULL);

    if (index == 0 || index + 8 >= buff->size(buff))
        return NULL;
    a = index - 1;
    b = index + 8;
    array->push_back(array, catch_str_ij(0, buff, a));
    array->push_back(array,
    catch_str_ij(b, buff, buff->size(buff)));
    return array;
}

lklist_str_t *get_answ_server(lklist_char_t *buff)
{
    lklist_char_t *catch = NULL;
    bool check = false;
    size_t i = 0;

    if (buff->size(buff) < 7)
        return get_answ_server_no_more_answ(buff);
    for (i = 0; i + 7 != buff->size(buff); i += 1) {
        catch = catch_str_ij(i, buff, i + 7);
        if (match_str(catch, "[ANSW]:") == 1)
            check = true;
        catch->free(catch);
        if (check == true)
            break;
    }
    if (check == true)
        return get_answ_server_f2(buff, i);
    else
        return get_answ_server_no_more_answ(buff);
    return NULL;
}

int isquoted(lklist_char_t *ll)
{
    int q = 0;

    if (ll->size(ll) >= 2) {
        for (size_t i = 0; i != ll->size(ll); i += 1) {
            if (ll->at(ll, i) == '"')
                q++;
        }
        if (q == 2 && ll->at(ll, 0) == '"' &&
        ll->at(ll, ll->size(ll) - 1) == '"')
            return 1;
    }
    return 0;
}