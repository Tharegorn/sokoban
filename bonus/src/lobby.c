/*
** EPITECH PROJECT, 2019
** SOKOBAN BONUS
** File description:
** lobby.c
*/

#include <ncurses.h>
#include "sokoban.h"
#include <stdlib.h>

void end(void)
{
    int ch;
    initscr;
    mvprintw(10, 10, "Vous avez gagné ! (Appuyez sur espace pour quitter.)");
    refresh();
    ch = getch();
    while (ch != 32)
        refresh();
    endwin();
    exit(0);
}