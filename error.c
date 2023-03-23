/*
** EPITECH PROJECT, 2022
** error*
** File description:
** error.c
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

void help(void)
{
    my_putstr("USAGE\n");
    my_putstr("     ./my_sokoban map\n");
    my_putstr("DESCRIPTION\n");
    my_putstr("     map  file representing the warehouse map, ");
    my_putstr("containing '#' for walls, \n");
    my_putstr("          'P' for the player, 'X' for boxes and ");
    my_putstr("'O' for storage locations.\n");
}

int map_checking(char **map)
{
    char *buffer = map_opener(map);

    for (int i = 0; i != my_strlen(buffer); i++) {
        if (buffer[i] != ' ' && buffer[i] != '\n' && buffer[i] != '#'
        && buffer[i] != 'X' && buffer[i] != 'O' && buffer[i] != 'P') {
            write(2, "The map you have provided is not val", 37);
            write(2, "id, please try again or use \"./my_s", 36);
            write(2, "okoban -h\" for more infomation\n", 32);
            return (84);
        }
    }
}

int box_checking(char **map, map_t *game)
{
    int store = 0;
    game->box = 0;
    char *buffer = map_opener(map);

    for (int i = 0; i != my_strlen(buffer); i++) {
        if (buffer[i] == 'O')
            store++;
        if (buffer[i] == 'X')
            game->box++;
    }
    if (game->box != store) {
        write(2, "The map you have provided is not valid, please try ", 52);
        write(2, "again or use \"./my_sokoban -h\" for more infomation\n", 52);
        return (84);
    }
}

int error(int ac, char **av, map_t *game)
{
    if (ac != 2)
        return (84);
    if (av[1][0] == '-' && av[1][1] == 'h') {
        help();
        return (84);
    }
    if (map_checking(av) == 84)
        return (84);
    if (box_checking(av, game) == 84)
        return (84);
    return (0);
}
