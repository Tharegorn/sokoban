/*
** EPITECH PROJECT, 2019
** h_explain.c
** File description:
** h_explain.c
*/

#include <unistd.h>

int usages(void)
{
    write(1, "USAGE\n     ./my_sokoban map\nDESCRIPTION\n     map file ", 54);
    write(1, "representing the warehouse map, containing '#' for walls,", 57);
    write(1, "\n         'P' for the player, 'X' for boxes 'O' for ", 52);
    write(1, "storage locations.\n", 19);
    return (0);
}