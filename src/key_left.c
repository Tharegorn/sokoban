/*
** EPITECH PROJECT, 2019
** key_left.c
** File description:
** key_left.c
*/

#include "coords.h"
#include "sokoban.h"
#include <unistd.h>
#include <stdlib.h>

void key_left_o(char **m, coord_t *c)
{
    if (m[c->y][c->x - 2] == 'O') {
        c->k = c->y;
        c->l = c->x - 2;
    }
    m[c->y][c->x - 2] = m[c->y][c->x - 1];
    m[c->y][c->x - 1] = ' ';
}

int key_left(char **m, coord_t *c)
{
    if (m[c->y][c->x - 1] == '#')
        c->x++;
    if (m[c->y][c->x - 1] == 'X' && m[c->y][c->x - 2] == 'X') {
        c->x++;
    } else if (m[c->y][c->x - 1] == 'X' && m[c->y][c->x - 2] == '#') {
        return (0);
    }
    if (m[c->y][c->x - 1] == 'X') {
        key_left_o(m, c);
    }
    c->x--;
    return (0);
}
