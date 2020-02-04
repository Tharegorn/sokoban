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

int key_down(char **m, coord_t *c)
{
    if (m[c->y + 1][c->x] != 'X' && m[c->y + 1][c->x ] != '1' && m[c->y + 1][c->x] != '4') {
        if (m[c->y + 1][c->x] != 'O' && m[c->y + 1][c->x] != '2') {
            if (m[c->y + 1][c->x] != ' ' && m[c->y + 1][c->x] != '3') {
          c->y--;
            }
        }
    }
    if (m[c->y + 1][c->x] == 'X') {
        buff_list(c);
    }
    if (m[c->y + 1][c->x] == 'O') {
        clear();
        exit(0);
    }
    if (m[c->y + 1][c->x] == '1')
        buff_list_maps(c, c->map_a);
    if (m[c->y + 1][c->x] == '2')
        buff_list_maps(c, c->map_b);
    if (m[c->y + 1][c->x] == '3')
        buff_list_maps(c, c->map_c);
    if (m[c->y + 1][c->x] == '4')
        buff_list_maps(c, c->map_d);
    c->y++;
    return (0);
}
