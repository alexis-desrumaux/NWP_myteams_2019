/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019
** File description:
** tools
*/

#include "command.h"

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