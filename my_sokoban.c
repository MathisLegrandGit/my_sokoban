/*
** EPITECH PROJECT, 2022
** sokoban.c
** File description:
** box moving program
*/

#include "include/my.h"
#include "include/sokoban.h"
#include "ncurses.h"
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <string.h>

void display(map_t *game)
{
    for (int i = 0; i < array_len(game->map); i++)
        printw("%s\n", game->map[i]);
    refresh();
}

int my_sokoban(char **av, map_t *game)
{
    game->map = my_str_to_word_array(map_opener(av), '\n');
    game->save = my_str_to_word_array(map_opener(av), '\n');
    game->why = 0;
    game->ex = 0;

    initscr();
    curs_set(0);
    noecho();
    keypad(stdscr, true);
    while (1) {
        storage_coords(game);
        size_check(game);
        player_finder(game);
        moving_it(game, av);
        check_win(game);
        check_lose(game);
        refresh();
    }
}

int main(int ac, char **av)
{
    map_t game;

    if (error(ac, av, &game) == 84)
        return (84);
    my_sokoban(av, &game);
}
