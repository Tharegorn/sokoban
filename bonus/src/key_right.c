    /*
** EPITECH PROJECT, 2019
** key_right.c
** File description:
** key_right.c
*/

#include "coords.h"
#include "sokoban.h"
#include <ncurses.h>
#include <unistd.h>
#include <stdlib.h>

int key_right(char **m, coord_t *c)
{
    if (m[c->y][c->x + 1] != 'X' && m[c->y][c->x + 1] != '1' && m[c->y][c->x + 1] != '4') {
        if (m[c->y][c->x + 1] != 'O' && m[c->y][c->x + 1] != '2') {
            if (m[c->y][c->x + 1] != ' ' && m[c->y][c->x + 1] != '3') {
          c->x--;
            }
        }
    }
    if (m[c->y][c->x + 1] == 'X') {
        buff_list(c);
    }
    if (m[c->y][c->x + 1] == 'O') {
        clear();
        exit(0);
    }
    if (m[c->y][c->x + 1] == '1')
        buff_list_maps(c, c->map_a);
    if (m[c->y][c->x + 1] == '2')
        buff_list_maps(c, c->map_b);
    if (m[c->y][c->x + 1] == '3')
        buff_list_maps(c, c->map_c);
    if (m[c->y][c->x + 1] == '4')
        buff_list_maps(c, c->map_d);
    c->x++;
    return (0);
}
