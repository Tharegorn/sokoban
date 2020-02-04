/*
** EPITECH PROJECT, 2019
** main.c
** File description:
** main.c
*/

#include "coords.h"
#include "sokoban.h"
#include <ncurses.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

void create_string(coord_t *c)
{
    c->menu = malloc(sizeof(char) * 15);
    c->list = malloc(sizeof(char) * 19);
    c->map_a = malloc(sizeof(char) * 10);
    c->map_b = malloc(sizeof(char) * 10);
    c->map_c = malloc(sizeof(char) * 10);
    c->map_d = malloc(sizeof(char) * 10);
    c->menu = "utils/menu_open";
    c->list = "utils/menu_list_map";
    c->map_a = "maps/map_a";
    c->map_b = "maps/map_b";
    c->map_c = "maps/map_c";
    c->map_d = "maps/map_d";
}


int make_map(char *m, char *av, coord_t *c)
{
    int fd = open(av, O_RDONLY);
    char **map;
    char ch = '\n';
    int strc;

    //free(map);
    map = malloc(sizeof(char*) * (count_p(m) + 1));
    c->begin = 0;
    for (int i = 0; i != count_p(m); i++) {
        strc = my_strclen(m, c, ch);
        map[i] = malloc(sizeof(char) * (strc + 2));
        read(fd, map[i], strc + 1);
        map[i][strc] = '\0';
    }
    map[count_p(m)] = NULL;
    close(fd);
    if (sokoban(map, c) == 0)
          return (0);
    return (1);
}

void make_buffer(char *path, char *dest, coord_t *c)
{
    int fd = open(path, O_RDONLY);

    read(fd, dest, 10000);
    close(fd);
    make_map(dest, path, c);
}

void buff_list(coord_t *c)
{
    char *ma = malloc(sizeof(char) * 10000);
    int fd = open(c->list, O_RDONLY);

    read(fd, ma, 10000);
    close(fd);
    make_map(ma, c->list, c);
}
int main(int ac, char **av)
{
    coord_t *c = malloc(sizeof(coord_t));
    char *m = malloc(sizeof(char) * 10000);

    create_string(c);
    make_buffer(c->menu, m, c);
}
