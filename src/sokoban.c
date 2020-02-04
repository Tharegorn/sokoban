/*
** EPITECH PROJECT, 2019
** sokoban.c
** File description:
** sokoban.c
*/

#include "coords.h"
#include "sokoban.h"
#include <ncurses.h>
#include <stdlib.h>

int sokoban(char **m, coord_t *c)
{
    c->y = 0;
    c->x = 0;
    initscr();
    noecho();
    curs_set(FALSE);
    keypad(stdscr, TRUE);
    refresh();
    for (int i = 0; m[i] != NULL; i++) {
        for (int j = 0; m[i][j] != '\0'; j++) {
            if (m[i][j] == 'P') {
                c->y = i;
                c->x = j;
            }
        }
    }
    m[c->y][c->x] = ' ';
    key_manage(m, c);
    endwin();
    return (0);
}
