/*
** EPITECH PROJECT, 2019
** ALEXIS DESRUMAUX
** File description:
** file.c
*/

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include "mylib.h"
#include "linkedlist.h"

lklist_str_t *file_to_tab_str(int *size, char *str, lklist_str_t *file)
{
    lklist_char_t *string = NULL;

    if (*size < 1)
        str[0] = '\0';
    if (*size > 1) {
        if (str[*size - 1] == '\n')
            str[*size - 1] = '\0';
        else
            str[*size] = '\0';
    }
    if (*size != -1) {
        string = cv_string_to_nlklist(str);
        file->push_back(file, string);
        if (!file)
            return NULL;
    }
    return file;
}

lklist_str_t *file_to_tab(char *path)
{
    FILE *fd = fopen(path, "r");
    int size = 0;
    size_t bufsize = 0;
    char *str = NULL;
    lklist_str_t *file = lklist_str_init(NULL);

    if (!file || fd == NULL) {
        free(file);
        return NULL;
    }
    for (; 1; bufsize = 0, size = 0) {
        size = getline(&str, &bufsize, fd);
        file = file_to_tab_str(&size, str, file);
        if (file->size(file) == 0 || file == NULL)
            return (NULL);
        if (size == -1)
            break;
    }
    return file;
}