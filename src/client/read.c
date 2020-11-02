/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019
** File description:
** read
*/

#include "client.h"

lklist_char_t *fill_cmd(lklist_char_t *buff)
{
    lklist_char_t *cmd = lklist_char_init(NULL);

    for (size_t i = 0; i != buff->size(buff); i += 1) {
        if (buff->at(buff, i) != '\r' && buff->at(buff, i) != '\n') {
            cmd->push_back(cmd, buff->at(buff, i));
        }
    }
    return cmd;
}

lklist_char_t *read_ctrl_c(lklist_char_t *buff, lklist_char_t *cmd)
{
    buff->clear(buff);
    free(buff);
    free(cmd);
    return cpy_string_to_nlklist("^C");
}

lklist_char_t *read_fd(int fd)
{
    lklist_char_t *buff = lklist_char_init(NULL);
    lklist_char_t *cmd = lklist_char_init(NULL);
    char c;
    int nb = 0;

    while (1) {
        nb = read(fd, &c, 1);
        if (nb <= 0 || c == '\n')
            break;
        buff->push_back(buff, c);
    }
    if (nb <= 0 || buff->size(buff) == 0)
        return read_ctrl_c(buff, cmd);
    cmd = fill_cmd(buff);
    free(buff);
    return cmd;
}

