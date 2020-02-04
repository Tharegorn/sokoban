/*
** EPITECH PROJECT, 2019
** key_down.c
** File description:
** key_down.c
*/

#include "coords.h"
#include "sokoban.h"
#include <unistd.h>
#include <stdlib.h>

void key_down_o(char **m, coord_t *c)
{
    if (m[c->y + 2][c->x] == 'O') {
        c->k = c->y + 2;
        c->l = c->x;
    }
    m[c->y + 2][c->x] = m[c->y + 1][c->x];
    if (m[c->y + 1][c->x] == '#');
    else
        m[c->y + 1][c->x] = ' ';
}

int key_down(char **m, coord_t *c)
{
    if (m[c->y + 1][c->x] == '#')
        c->y--;
    if (m[c->y + 1][c->x] == 'X' && m[c->y + 2][c->x] == 'X') {
        c->y--;
    }
    if (m[c->y + 1][c->x] == 'X' && m[c->y + 2][c->x] == '#') {
        return (0);
    }
    if (m[c->y + 1][c->x] == 'X') {
        key_down_o(m, c);
    }
    c->y++;
    return (0);
}
