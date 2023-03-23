/*
** EPITECH PROJECT, 2022
** the most important part of the game basically
** File description:
** moving dem chars
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

void move_down2(map_t *game)
{
    if (game->map[game->player_y + 2][game->player_x] == 'O') {
        game->map[game->player_y + 2][game->player_x] = 'X';
        game->map[game->player_y + 1][game->player_x] = 'P';
        game->map[game->player_y][game->player_x] = ' ';
        return;
    }
    if (game->map[game->player_y + 1][game->player_x] == 'X') {
        if (game->map[game->player_y + 2][game->player_x] != '#'
        && game->map[game->player_y + 2][game->player_x] != 'X') {
            game->map[game->player_y][game->player_x] = ' ';
            game->map[game->player_y + 1][game->player_x] = 'P';
            game->map[game->player_y + 2][game->player_x] = 'X';
            game->player_y++;
            return;
        }
    }
}

void move_up2(map_t *game)
{
    if (game->map[game->player_y - 2][game->player_x] == 'O') {
        game->map[game->player_y - 2][game->player_x] = 'X';
        game->map[game->player_y - 1][game->player_x] = 'P';
        game->map[game->player_y][game->player_x] = ' ';
        game->player_y--;
        return;
    }
    if (game->map[game->player_y - 1][game->player_x] == 'X') {
        if (game->map[game->player_y - 2][game->player_x] != '#'
        && game->map[game->player_y - 2][game->player_x] != 'X') {
            game->map[game->player_y][game->player_x] = ' ';
            game->map[game->player_y - 1][game->player_x] = 'P';
            game->map[game->player_y - 2][game->player_x] = 'X';
            game->player_y--;
            return;
        }
    }
}

void move_left2(map_t *game)
{
    if (game->map[game->player_y][game->player_x - 2] == 'O') {
        game->map[game->player_y][game->player_x - 2] = 'X';
        game->map[game->player_y][game->player_x - 1] = 'P';
        game->map[game->player_y][game->player_x] = ' ';
        game->player_x--;
        return;
    }
    if (game->map[game->player_y][game->player_x - 1] == 'X') {
        if (game->map[game->player_y][game->player_x - 2] != '#'
        && game->map[game->player_y][game->player_x - 2] != 'X') {
            game->map[game->player_y][game->player_x] = ' ';
            game->map[game->player_y][game->player_x - 1] = 'P';
            game->map[game->player_y][game->player_x - 2] = 'X';
            game->player_x--;
            return;
        }
    }
}

void move_right2(map_t *game)
{
    if (game->map[game->player_y][game->player_x + 2] == 'O') {
        game->map[game->player_y][game->player_x + 2] = 'X';
        game->map[game->player_y][game->player_x + 1] = 'P';
        game->map[game->player_y][game->player_x] = ' ';
        game->player_x++;
        return;
    }
    if (game->map[game->player_y][game->player_x + 1] == 'X') {
        if (game->map[game->player_y][game->player_x + 2] != '#'
        && game->map[game->player_y][game->player_x + 2] != 'X') {
            game->map[game->player_y][game->player_x] = ' ';
            game->map[game->player_y][game->player_x + 1] = 'P';
            game->map[game->player_y][game->player_x + 2] = 'X';
            game->player_x++;
            return;
        }
    }
}

void storage_replace(map_t *game)
{
    int a = 0;
    int b = 0;

    while (game->map[a] != NULL) {
        if (game->save[a][b] == 'O' && game->map[a][b] == ' ') {
            game->map[a][b] = 'O';
        }
        if (game->save[a][b] == '\0') {
            a++;
            b = 0;
        }
        b++;
    }
}
