/*
** EPITECH PROJECT, 2022
** my_str_to_word_array
** File description:
** my_str_to_word_array
*/

#include "../../include/my.h"
#include <stdio.h>
#include <stdlib.h>

int str_len(char *str, char separator, int b)
{
    int a = 0;

    while (str[b] != '\0' || str[b] != separator) {
        if (str[b] == '\0' || str[b] == separator) {
            return (a);
        }
        a++;
        b++;
    }
    return (a);
}

int array_nbr(char *str, char separator)
{
    int a = 1;
    int b = 0;

    while (str[b] != '\0') {
        if (str[b] == '\0' || str[b] == separator) {
            a++;
        }
        b++;
    }
    return (a);
}

char **my_str_to_word_array(char *str, char separator)
{
    int str_nbr;
    int a = 0;
    int y = 0;
    int b = array_nbr(str, separator);
    char **array = malloc(sizeof(char*) * (b + 1));

    for (int x = 0; x < b; x++) {
        str_nbr = (str_len(str, separator, a));
        array[x] = malloc(sizeof(char) * (str_nbr + 1));
        for (int j = 0; j < str_nbr && str[a] != '\0'; j++) {
            array[x][y] = str[a];
            y++;
            a++;
        }
        array[x][y] = '\0';
        a++;
        y = 0;
    }
    array[b] = NULL;
    return (array);
}
