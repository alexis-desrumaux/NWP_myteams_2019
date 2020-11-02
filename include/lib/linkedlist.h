/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019
** File description:
** linkedlist
*/

#ifndef LINKEDLIST_H_
#define LINKEDLIST_H_

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

typedef struct lklist_char_s
{
    char _elem;
    size_t _size;
    struct lklist_char_s *_prev;
    struct lklist_char_s *_next;
    void (*push_back)(struct lklist_char_s *ll, char c);
    void (*pop_back)(struct lklist_char_s *ll);
    char (*at)(struct lklist_char_s *ll, size_t index);
    size_t (*size)(struct lklist_char_s *ll);
    void (*clear)(struct lklist_char_s *ll);
    void (*erase)(struct lklist_char_s *ll, size_t index);
    void (*insert)(struct lklist_char_s *ll, size_t index, char c);
    void (*fill)(struct lklist_char_s *ll, char *str);
    void (*lkl_fill)(struct lklist_char_s *ll, struct lklist_char_s *new);
    void (*set)(struct lklist_char_s *ll, size_t index, char c);
    char *(*to_str)(struct lklist_char_s *ll);
    void (*free)(struct lklist_char_s *ll);
} lklist_char_t;

typedef struct lklist_str_s
{
    lklist_char_t *_elem;
    size_t _size;
    struct lklist_str_s *_prev;
    struct lklist_str_s *_next;
    void (*push_back)(struct lklist_str_s *ll, lklist_char_t *str);
    void (*pop_back)(struct lklist_str_s *ll);
    lklist_char_t *(*at)(struct lklist_str_s *ll, size_t index);
    size_t (*size)(struct lklist_str_s *ll);
    void (*clear)(struct lklist_str_s *ll);
    void (*erase)(struct lklist_str_s *ll, size_t index);
    void (*insert)(struct lklist_str_s *ll, size_t index, lklist_char_t *str);
    void (*fill)(struct lklist_str_s *ll, char **array);
    void (*lkl_fill)(struct lklist_str_s *ll, struct lklist_str_s *new);
    void (*set)(struct lklist_str_s *ll, size_t index, lklist_char_t *str);
    void (*free)(struct lklist_str_s *ll);
} lklist_str_t;

typedef struct lklist_int_s
{
    int _elem;
    size_t _size;
    struct lklist_int_s *_prev;
    struct lklist_int_s *_next;
    void (*push_back)(struct lklist_int_s *ll, int nb);
    void (*pop_back)(struct lklist_int_s *ll);
    int (*at)(struct lklist_int_s *ll, size_t index);
    size_t (*size)(struct lklist_int_s *ll);
    void (*clear)(struct lklist_int_s *ll);
    void (*erase)(struct lklist_int_s *ll, size_t index);
} lklist_int_t;

typedef struct lklist_s
{
    void *_elem;
    size_t _size;
    struct lklist_s *_prev;
    struct lklist_s *_next;
    char *_type;
    void (*push_back)(struct lklist_s *ll, void *elem, char *type);
    void (*pop_back)(struct lklist_s *ll);
    void *(*at)(struct lklist_s *ll, size_t index);
    size_t (*size)(struct lklist_s *ll);
    void (*clear)(struct lklist_s *ll);
    void (*erase)(struct lklist_s *ll, size_t index);
    void (*insert)(struct lklist_s *ll, size_t index, void *elem, char *type);
    char *(*get_type)(struct lklist_s *ll, size_t index);

} lklist_t;

//linkedlist.c
lklist_t *lklist_init(void);
//linkedlist_str.c
lklist_str_t *lklist_str_init(char **array);
lklist_str_t *lklist_str_lklinit(lklist_str_t *new);
//linkedlist_char.c
lklist_char_t *lklist_char_init(char *str);
lklist_char_t *lklist_char_lklinit(lklist_char_t *str);
//linkedlist_int.c
lklist_int_t *lklist_int_init(void);

//char/tools.c
lklist_char_t *cpy_string_to_nlklist(char *str);
lklist_char_t *cv_string_to_nlklist(char *str);
char *cpy_lklist_to_nstring(lklist_char_t *list);
char *cv_lklist_to_nstring(lklist_char_t *list);

#endif /* !LINKEDLIST_H_ */
