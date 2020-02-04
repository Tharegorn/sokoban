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

int make_map(char *m, char *av)
{
    coord_t *c = malloc(sizeof(coord_t));
    int fd = open(av, O_RDONLY);
    char **map;
    char ch = '\n';
    int strc;

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

int check_map(char *m)
{
    for (int i = 0; m[i] != '\0'; i++) {
        if (m[i] != '#' && m[i] != 'X' && m[i] != 'O' && m[i] != ' ') {
            if (m[i] != '\n' && m[i] != 'P') {
                return (1);
            }
        }
    }
    return (0);
}

int check_box(char *m)
{
    int box = 0;
    int stack = 0;

    for (int i = 0; m[i] != '\0'; i++) {
        if (m[i] == 'X')
            box ++;
        if (m[i] == 'O')
            stack++;
    }
    if (stack != box)
        return (84);
    if (stack == 0 || box == 0)
        return (84);
    return (0);
}

int main(int ac, char **av)
{
    int fd;
    char *m = malloc(sizeof(char) * 10000);

    if (ac != 2)
        return (84);
    if (av[1][0] == '-' && av[1][1] == 'h')
        usages();
    fd = open(av[1], O_RDONLY);
    read(fd, m, 10000);
    if (check_box(m) == 84)
        return (84);
    if (check_map(m) == 1)
        return (84);
    close(fd);
    make_map(m, av[1]);
}
