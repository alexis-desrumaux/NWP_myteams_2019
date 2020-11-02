/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019
** File description:
** func_linkedlist
*/

#ifndef FUNC_LINKEDLIST_H_
#define FUNC_LINKEDLIST_H_

#include "linkedlist.h"

//*********MTYPES**********//
//linkedlist.c
size_t lklist_size(lklist_t *ll);
void *lklist_at(lklist_t *ll, size_t index);
void lklist_pop_back(lklist_t *ll);
void lklist_push_back(lklist_t *ll, void *elem, char *type);

//linkedlist2.c
void lklist_clear(lklist_t *ll);
void lklist_erase(lklist_t *ll, size_t index);

//linkedlist3.c
void lklist_insert(lklist_t *ll, size_t index, void *elem, char *type);
char *lklist_get_type(lklist_t *ll, size_t index);

//*********STRING*********//

//linkedlist_str.c
void lklist_str_pop_back(lklist_str_t *ll);
void lklist_str_push_back(lklist_str_t *ll, lklist_char_t *str);
void lklist_str_init_func(lklist_str_t *ll);

//linkedlist_str_2.c
lklist_char_t *lklist_str_at(lklist_str_t *ll, size_t index);
void lklist_str_clear(lklist_str_t *ll);
void lklist_str_erase(lklist_str_t *ll, size_t index);

//linkedlist_str_3.c
size_t lklist_str_size(lklist_str_t *ll);
void lklist_str_insert(lklist_str_t *ll, size_t index, lklist_char_t *str);

//linkedlist_str_4.c
void lklist_str_set(lklist_str_t *ll, size_t index, lklist_char_t *str);
void lklist_str_strfill(lklist_str_t *ll, char **array);
void lklist_str_lklfill(lklist_str_t *ll, lklist_str_t *new);
void lklist_str_free(lklist_str_t *ll);

//*********CHAR**********//

//linkedlist_char.c
void lklist_char_pop_back(lklist_char_t *ll);
void lklist_char_push_back(lklist_char_t *ll, char c);
void lklist_char_init_func(lklist_char_t *ll);

//linkedlist_char_2.c
char lklist_char_at(lklist_char_t *ll, size_t index);
void lklist_char_clear(lklist_char_t *ll);
void lklist_char_erase(lklist_char_t *ll, size_t index);

//linkedlist_char_3.c
size_t lklist_char_size(lklist_char_t *ll);
void lklist_char_insert(lklist_char_t *ll, size_t index, char c);

//linkedlist_char_4.c
void lklist_char_set(lklist_char_t *ll, size_t index, char c);
void lklist_char_cfill(lklist_char_t *ll, char *str);
void lklist_char_lklfill(lklist_char_t *ll, lklist_char_t *new);
char *lklist_char_to_str(lklist_char_t *ll);
void lklist_char_free(lklist_char_t *ll);

//*********INT**********//

//linkedlist_int.c
size_t lklist_int_size(lklist_int_t *ll);
int lklist_int_at(lklist_int_t *ll, size_t index);
void lklist_int_pop_back(lklist_int_t *ll);
void lklist_int_push_back(lklist_int_t *ll, int nb);

//linkedlist_int_2.c
void lklist_int_clear(lklist_int_t *ll);
void lklist_int_erase(lklist_int_t *ll, size_t index);

//linkedlist_int_3.c
void lklist_int_insert(lklist_int_t *ll, size_t index, int nb);

#endif /* !FUNC_LINKEDLIST_H_ */
