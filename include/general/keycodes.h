/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019
** File description:
** keycodes
*/

#ifndef KEYCODES_H_
#define KEYCODES_H_

typedef struct keycodes_s
{
    char *connected;
    char *invalid;
    char *valid_no_r;
    char *valid_w_r;
    char *already_exist;
    char *unauthorised;
    char *user_n_exist;
    char *too_long_body;
    char *exit;
    char *user_connected;
    char *user_disconnected;
} keycodes_t;

static const keycodes_t keycodes =
{
    "[0] SUCCESSFULY CONNECTED !",
    "[1] Bad command",
    "[2] Command OK",
    "[3] Command OK. Send...",
    "[4] Already exist",
    "[5] Unauthorised to see this content",
    "[6] User doesn't exist",
    "[7] Too long body",
    "[8] Exit",
    "[9] A User is connected",
    "[10] A User is disconnected",
};

#endif /* !KEYCODES_H_ */
