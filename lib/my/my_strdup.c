/*
** EPITECH PROJECT, 2022
** my_strdup
** File description:
** strdup
*/

#include "../../include/my.h"
#include <stdlib.h>

char *my_strdup(char const *src)
{
    int i = 0;
    char *adress;

    adress = malloc(sizeof(char) * my_strlen(src) + 1);
    while (src[i] != '\0') {
        adress[i] = src[i];
        i = i + 1;
    }
    adress[i] = '\0';
    return (adress);
}
