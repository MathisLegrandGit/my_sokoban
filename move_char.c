/*
** EPITECH PROJECT, 2022
** move_char
** File description:
** moving the player up, down, left, and right
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

void move_down(map_t *game)
{
    if (game->map[game->player_y + 1][game->player_x] == '#')
        return;
    if (game->map[game->player_y + 1][game->player_x] == ' ') {
        game->map[game->player_y][game->player_x] = ' ';
        game->map[game->player_y + 1][game->player_x] = 'P';
        game->player_y++;
        return;
    }
    if (game->map[game->player_y + 1][game->player_x] == 'O') {
        game->map[game->player_y][game->player_x] = ' ';
        game->map[game->player_y + 1][game->player_x] = 'P';
        game->player_y++;
        return;
    }
    move_down2(game);
}

void move_up(map_t *game)
{
    if (game->map[game->player_y - 1][game->player_x] == '#')
        return;
    if (game->map[game->player_y - 1][game->player_x] == ' ') {
        game->map[game->player_y][game->player_x] = ' ';
        game->map[game->player_y - 1][game->player_x] = 'P';
        game->player_y--;
        return;
    }
    if (game->map[game->player_y - 1][game->player_x] == 'O') {
        game->map[game->player_y][game->player_x] = ' ';
        game->map[game->player_y - 1][game->player_x] = 'P';
        game->player_y--;
        return;
    }
    move_up2(game);
}

void move_left(map_t *game)
{
    if (game->map[game->player_y][game->player_x - 1] == ' ') {
        game->map[game->player_y][game->player_x] = ' ';
        game->map[game->player_y][game->player_x - 1] = 'P';
        game->player_x--;
        return;
    }
    if (game->map[game->player_y][game->player_x - 1] == 'O') {
        game->map[game->player_y][game->player_x] = ' ';
        game->map[game->player_y][game->player_x - 1] = 'P';
        game->player_x--;
        return;
    }
    move_left2(game);
}

void move_right(map_t *game)
{
    if (game->map[game->player_y][game->player_x + 1] == ' ') {
        game->map[game->player_y][game->player_x] = ' ';
        game->map[game->player_y][game->player_x + 1] = 'P';
        game->player_x++;
        return;
    }
    if (game->map[game->player_y][game->player_x + 1] == 'O') {
        game->map[game->player_y][game->player_x] = ' ';
        game->map[game->player_y][game->player_x + 1] = 'P';
        game->player_x++;
        return;
    }
    move_right2(game);
}

int moving_it(map_t *game, char **av)
{
    game->key = getch();
    if (game->key == 258)
        move_down(game);
    if (game->key == 259)
        move_up(game);
    if (game->key == 260)
        move_left(game);
    if (game->key == 261)
        move_right(game);
    if (game->key == 32) {
        clear();
        my_sokoban(av, game);
    }
    storage_coords(game);
    storage_replace(game);
    clear();
}
