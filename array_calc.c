/*
** EPITECH PROJECT, 2022
** exactly
** File description:
** calculations and the file opening file
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

char *map_opener(char **av)
{
    char *buffer = NULL;
    int size = 0;
    char *map = av[1];
    int file_descriptor = open(map, O_RDONLY);
    struct stat s;

    if (file_descriptor == -1) {
        write(2, "Please provide a valid file\n", 28);
        exit (84);
    }
    stat(map, &s);
    size = s.st_size;
    buffer = malloc(sizeof(char) * (size + 2));
    read(file_descriptor, buffer, size);
    buffer[s.st_size] = '\0';
    return (buffer);
}

int max_str(char **map)
{
    int a = 0;
    int i = my_strlen(map[a]);

    while (map[a + 1] != NULL) {
        a++;
        if (my_strlen(map[a]) > i)
            i = my_strlen(map[a]);
    }
    return (i);
}

int array_len(char **map)
{
    int a = 0;

    while (map[a] != NULL) {
        a++;
    }
    return (a);
}

int check_lose2(map_t *game, int line, int x, int y)
{
    if ((game->map[y - 1][x] == '#' && game->map[y][x + 1] == '#') ||
    (game->map[y - 1][x] == '#' && game->map[y][x - 1] == '#') ||
    (game->map[y + 1][x] == '#' && game->map[y][x - 1] == '#') ||
    (game->map[y + 1][x] == '#' && game->map[y][x + 1] == '#')) {
        line++;
    }
    return (line);
}

int check_lose(map_t *game)
{
    int y = 0;
    int line = 0;

    for (int x = 0; game->map[y] != NULL; x++) {
        if (game->map[y][x] == 'X') {
            line = check_lose2(game, line, x , y);
        }
        if (game->map[y][x] == '\0') {
            y++;
            x = 0;
        }
    }
    if (game->box == line) {
        display(game);
        endwin();
        write(2, "Oops, you lost!!\n", 18);
        exit (1);
    }
}
