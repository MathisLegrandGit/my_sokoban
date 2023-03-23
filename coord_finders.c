/*
** EPITECH PROJECT, 2022
** coord finders
** File description:
** functions that find the coordinates of certain objects or players
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

void size_check(map_t *game)
{
    game->erreur = "Enlarge You're Terminal Window";

    getmaxyx(stdscr, game->y, game->x);
    if (game->y < array_len(game->map) || game->x < max_str(game->map)) {
        mvprintw((game->y / 2), ((game->x / 2) -
        (my_strlen(game->erreur) / 2)), game->erreur);
    } else {
        display(game);
    }
}

void player_finder(map_t *game)
{
    game->player_x = 0;
    game->player_y = 0;
    while (game->map[game->player_y][game->player_x] != 'P') {
        game->player_x++;
        if (game->map[game->player_y][game->player_x] == '\0') {
            game->player_y++;
            game->player_x = 0;
        }
    }
}

void storage_coords(map_t *game)
{
    int a = 0;
    int b = 0;
    game->c = 0;

    storage_replace(game);
    while (game->map[a] != NULL) {
        if (game->map[a][b] == 'O') {
            game->why = a;
            game->ex = b;
            game->c++;
        }
        if (game->save[a][b] == '\0') {
            a++;
            b = 0;
        }
        b++;
    }
}

void check_win(map_t *game)
{
    storage_coords(game);
    if (game->c == 0 && game->map[game->why][game->ex] !=
    game->map[game->player_y][game->player_x]) {
        display(game);
        endwin();
        write(2, "Good Job, you won!!\n", 21);
        exit(0);
    }
}
