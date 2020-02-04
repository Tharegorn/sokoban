/*
** EPITECH PROJECT, 2019
** key_manage.c
** File description:
** key_manage.c
*/

#include "coords.h"
#include "sokoban.h"
#include <ncurses.h>
#include <unistd.h>
#include <stdlib.h>

void switcher(int ch, char **m, coord_t *c)
{
    switch (ch) {
    case KEY_DOWN:
        key_down(m, c);
        break;
    case KEY_UP:
        key_up(m, c);
        break;
    case KEY_LEFT:
        key_left(m, c);
        break;
    case KEY_RIGHT:
        key_right(m, c);
        break;
    case 32:
        break;
    }
}

void printer(char **m, coord_t *c)
{
    clear();
    for (int i = 0; m[i] != NULL; i++) {
        mvprintw(i,0,m[i]);
    }
    mvprintw(c->y, c->x, "P");
    refresh();
}

int key_manage(char **m, coord_t *c)
{
    int ch;

    c->k = 0;
    c->l = 0;
    while (1) {
        printer(m, c);
        ch = getch();
        switcher(ch, m, c);
    }
}
