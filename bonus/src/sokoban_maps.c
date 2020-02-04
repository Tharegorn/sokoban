/*
** EPITECH PROJECT, 2019
** SOKOBAN-BONUS
** File description:
** sokoban_maps.c
*/

#include "coords.h"
#include "sokoban.h"
#include <ncurses.h>
#include <stdlib.h>

int sokoban_maps(char **m, coord_t *c)
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
    key_manage_maps(m, c);
    endwin();
    return (0);
}
