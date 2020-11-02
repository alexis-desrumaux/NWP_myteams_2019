/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019
** File description:
** parse_command
*/

#include "server.h"

void parse_command_f5(lklist_char_t *nq, lklist_char_t *str,
lklist_str_t *array, lklist_char_t *topush)
{
    bool check = false;

    for (size_t i = 0; i != nq->size(nq); i += 1) {
        if (nq->at(nq, i) != ' ' && nq->at(nq, i) != '\t') {
            if (nq->at(nq, i) == '#')
                topush->push_back(topush, str->at(str, i));
            else
                topush->push_back(topush, nq->at(nq, i));
            check = false;
        }
        if (nq->at(nq, i) == ' ' || nq->at(nq, i) == '\t') {
            if (check == false) {
                array->push_back(array, topush);
                topush = lklist_char_init(NULL);
            }
            check = true;
        }
    }
    array->push_back(array, topush);
}

lklist_str_t *parse_command_f4(lklist_char_t *nq, lklist_char_t *str)
{
    lklist_str_t *array = lklist_str_init(NULL);
    lklist_char_t *topush = lklist_char_init(NULL);

    parse_command_f5(nq, str, array, topush);
    nq->free(nq);
    str->free(str);
    return array;
}

lklist_str_t *parse_command_f3(lklist_char_t *nq, lklist_char_t *str)
{
    size_t i = 0;
    size_t j = 0;
    lklist_char_t *nq_clean = NULL;
    lklist_char_t *str_clean = NULL;

    for (; i != nq->size(nq) && (nq->at(nq, i) == ' ' ||
    nq->at(nq, i) == '\t'); i += 1);
    if (i == nq->size(nq))
        return NULL;
    j = nq->size(nq) - 1;
    for (; nq->at(nq, j) == ' ' || nq->at(nq, j) == '\t'; j -= 1) {
        if (j == 0)
            break;
    }
    j += 1;
    if (i == j)
        return NULL;
    nq_clean = catch_str_ij(i, nq, j);
    str_clean = catch_str_ij(i, str, j);
    return parse_command_f4(nq_clean, str_clean);
}

bool parse_command_f2(bool check, lklist_char_t *nquotes)
{
    if (check == false) {
        nquotes->push_back(nquotes, '#');
        check = true;
    }
    else if (check == true) {
        nquotes->push_back(nquotes, '#');
        check = false;
    }
    return check;
}

lklist_str_t *parse_command(lklist_char_t *str)
{
    lklist_char_t *nquotes = lklist_char_init(NULL);
    lklist_str_t *array = NULL;
    bool check = false;

    for (size_t i = 0; i != str->size(str); i += 1) {
        if (str->at(str, i) == '"')
            check = parse_command_f2(check, nquotes);
        else if (str->at(str, i) != '"' && check == false)
            nquotes->push_back(nquotes, str->at(str, i));
        else if (str->at(str, i) != '"' && check == true)
            nquotes->push_back(nquotes, '#');
    }
    array = parse_command_f3(nquotes, str);
    nquotes->free(nquotes);
    return array;
}