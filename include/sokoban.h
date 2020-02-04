/*
** EPITECH PROJECT, 2019
** sokoban.h
** File description:
** sokoban header
*/

#include "coords.h"
#ifndef header

int key_right(char **m, coord_t *c);
int key_down(char **m, coord_t *c);
int key_up(char **m, coord_t *c);
int key_left(char **m, coord_t *c);
int key_manage(char **m, coord_t *c);
int end(void);
int key_left(char **m, coord_t *c);
int key_up(char **m, coord_t *c);
int key_down(char **m, coord_t *c);
int key_right(char **m, coord_t *c);
int sokoban(char **m, coord_t *c);
int usages(void);
int count_p(char *m);
int count_k(char *m);
int my_strclen(char *str, coord_t *c, char ch);

#endif
