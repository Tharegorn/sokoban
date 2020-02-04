/*
** EPITECH PROJECT, 2019
** SOKOBAN-BONUS
** File description:
** key_manage_maps.c
*/

#include "coords.h"
#include "sokoban.h"
#include <ncurses.h>
#include <unistd.h>
#include <stdlib.h>

void check_o(char **m, coord_t *c)
{
    if (m[c->k][c->l] == ' ')
        m[c->k][c->l] = 'O';
    c->o = 0;
    for (int i = 0; m[i] != NULL; i++) {
        for (int j = 0; m[i][j] != '\0'; j++) {
            if (m[i][j] == 'O') {
                c->o++;
            }
        }
    }
    if (c->o == 0) {
        c->scre = 2;
    }
}

void switcher_maps(int ch, char **m, coord_t *c)
{
    switch (ch) {
    case KEY_DOWN:
        key_down_maps(m, c);
        break;
    case KEY_UP:
        key_up_maps(m, c);
        break;
    case KEY_LEFT:
        key_left_maps(m, c);
        break;
    case KEY_RIGHT:
        key_right_maps(m, c);
        break;
    case 32:
        break;
    }
}

void printer_maps(char **m, coord_t *c)
{
    clear();
    for (int i = 0; m[i] != NULL; i++) {
        mvprintw(i,0,m[i]);
    }
    mvprintw(c->y, c->x, "P");
    refresh();
}

int key_manage_maps(char **m, coord_t *c)
{
    int ch;

    c->k = 0;
    c->l = 0;
    while (1) {
        printer_maps(m, c);
        if (c->scre == 2) {
            clear();
            endwin();
            end();
        }
        ch = getch();
        switcher_maps(ch, m, c);
        check_o(m, c);
    }
}
