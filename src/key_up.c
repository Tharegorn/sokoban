/*
** EPITECH PROJECT, 2019
** key_up.c
** File description:
** key_up.c
*/

#include "coords.h"
#include "sokoban.h"
#include <unistd.h>
#include <stdlib.h>

void key_up_o(char **m, coord_t *c)
{
    if (m[c->y - 2][c->x] == 'O') {
        c->k = c->y - 2;
        c->l = c->x;
    }
    m[c->y - 2][c->x] = m[c->y - 1][c->x];
    m[c->y - 1][c->x] = ' ';
}

int key_up(char **m, coord_t *c)
{
    if (m[c->y - 1][c->x] == '#')
        c->y++;
    if (m[c->y - 1][c->x] == 'X' && m[c->y - 2][c->x] == 'X') {
        c->y++;
    } 
    if (m[c->y - 1][c->x] == 'X' && m[c->y - 2][c->x] == '#') {
        return (0);
    }
    if (m[c->y - 1][c->x] == 'X') {
        key_up_o(m, c);
    }
    c->y--;
    return (0);
}
