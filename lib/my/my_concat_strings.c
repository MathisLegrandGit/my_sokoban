/*
** EPITECH PROJECT, 2021
** concat_strings
** File description:
** concatenates two strings together
*/

#include "../../include/my.h"

char *concat_strings(char *dest, char const *src)
{
    int i = 0;
    int c = 0;
    char *str1 = my_strdup(dest);
    char *str = my_strdup(src);

    while (str1[i] != '\0') {
        i++;
    }
    while (str[c] != '\0') {
        str1[i] = str[c];
        c++;
        i++;
    }
    str1[i] = '\0';
    return (str1);
}
