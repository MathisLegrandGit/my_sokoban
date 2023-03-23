/*
** EPITECH PROJECT, 2021
** my_strcmp
** File description:
** yes
*/

#include "../../include/my.h"

int my_strcmp(char *str, char *word)
{
    int j = 0;

    if (my_strlen(str) != my_strlen(word))
        return 1;
    for (int i = 0; str[i] != '\0'; i++){
        if (str[i] == word[i]) {
            j++;
        }
    }
    if (j == my_strlen(word)){
        return 0;
    } else {
        return 1;
    }
}
