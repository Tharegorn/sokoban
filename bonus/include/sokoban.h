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
void end(void);
int key_left(char **m, coord_t *c);
int key_up(char **m, coord_t *c);
int key_down(char **m, coord_t *c);
int key_right(char **m, coord_t *c);
int sokoban(char **m, coord_t *c);
int usages(void);
int count_p(char *m);
int count_k(char *m);
int my_strclen(char *str, coord_t *c, char ch);
void printer_maps(char **m, coord_t *c);
int key_manage_maps(char **m, coord_t *c);
void switcher_maps(int ch, char **m, coord_t *c);
int key_up_maps(char **m, coord_t *c);
int key_down_maps(char **m, coord_t *c);
int key_left_maps(char **m, coord_t *c);
int key_right_maps(char **m, coord_t *c);
int sokoban_maps(char **m, coord_t *c);
int make_maps(char *m, char *av, coord_t *c);
void buff_list_maps(coord_t *c, char *path);
void buff_list(coord_t *c);
#endif
