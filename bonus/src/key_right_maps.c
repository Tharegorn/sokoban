/*
** EPITECH PROJECT, 2019
** SOKOBAN-BONUS
** File description:
** key_right_maps.c
*/

#include "coords.h"
#include "sokoban.h"
#include <unistd.h>
#include <stdlib.h>

void key_right_o(char **m, coord_t *c)
{
    if (m[c->y][c->x + 2] == 'O') {
        c->k = c->y;
        c->l = c->x + 2;
    }
    m[c->y][c->x + 2] = m[c->y][c->x + 1];
    m[c->y][c->x + 1] = ' ';
}

int key_right_maps(char **m, coord_t *c)
{
    if (m[c->y][c->x + 1] == '#')
        c->x--;
    if (m[c->y][c->x + 1] == 'X' && m[c->y][c->x + 2] == 'X') {
        c->x--;
    } 
    if (m[c->y][c->x + 1] == 'X' && m[c->y][c->x + 2] == '#') {
        return (0);
    }
    if (m[c->y][c->x + 1] == 'X') {
        key_right_o(m, c);
    }
    c->x++;
    return (0);
}
