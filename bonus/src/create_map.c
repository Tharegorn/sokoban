/*
** EPITECH PROJECT, 2019
** SOKOBAN-BONUS
** File description:
** create-map.c
*/

#include "coords.h"
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>

int make_maps(char *m, char *av, coord_t *c)
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
    if (sokoban_maps(map, c) == 0)
          return (0);
    return (1);
}

void buff_list_maps(coord_t *c, char *path)
{
    char *mb = malloc(sizeof(char) * 10000);
    int fd = open(path, O_RDONLY);

    read(fd, mb, 10000);
    close(fd);
    make_maps(mb, path, c);
}
