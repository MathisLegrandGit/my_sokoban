/*
** EPITECH PROJECT, 2019
** sokoban.h
** File description:
** sokoban header
*/

#ifndef my_sokoban_h_
    #define my_sokoban_h_

typedef struct map {
    int y;
    int x;
    int player_x;
    int player_y;
    int store_x;
    int store_y;
    int key;
    char **av;
    char **map;
    char **save;
    char *erreur;
    int box;
    int c;
    int d;
    int loop;
    int why;
    int ex;
}map_t;

    int main(int ac, char **av);
    int error(int ac, char **av, map_t *game);
    int my_sokoban(char **av, map_t *game);
    void display(map_t *game);
    int box_checking(char **map, map_t *game);
    int map_checking(char **map);
    int max_str(char **map);
    int array_len(char **map);
    char *map_opener(char **av);
    int moving_it(map_t *game, char **av);
    void store_finder(map_t *game);
    void player_finder(map_t *game);
    void size_check(map_t *game);
    void move_down(map_t *game);
    void move_up(map_t *game);
    void move_left(map_t *game);
    void move_right(map_t *game);
    void move_down2(map_t *game);
    void move_up2(map_t *game);
    void move_left2(map_t *game);
    void move_right2(map_t *game);
    void storage_replace(map_t *game);
    void storage_coords(map_t *game);
    int box_number(map_t *game);
    void check_win(map_t *game);
    int check_lose(map_t *game);
    int check_lose2(map_t *game, int line, int x , int y);

#endif
