/*
** EPITECH PROJECT, 2019
** counter.c
** File description:
** counter.c
*/

#include "coords.h"
#include "sokoban.h"
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int count_p(char *m)
{
    int p = 1;

    for (int j = 0; m[j] != '\0'; j++) {
        if (m[j] == '\n')
            p++;
    }
    return (p);
}

int count_k(char *m)
{
    int k = 0;

    while (m[k] != '\n') {
        k++;
    }
    return (k);
}

int my_strclen(char *str, coord_t *c, char ch)
{
    int i = 0;

    if (c->begin != 0)
        c->begin++;
    while (str[c->begin] != '\0' && str[c->begin] != ch) {
        c->begin++;
        i++;
    }
    return (i);
}
