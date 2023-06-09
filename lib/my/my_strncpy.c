/*
** EPITECH PROJECT, 2021
** my_strncpy
** File description:
** yes
*/

char *my_strncpy(char *dest, char const *src, int n)
{
    int i = 0;

    while (i < n && src[i] != '\0') {
        dest[i] = src[i];
        i += 1;
    }
    if (i < n) {
        dest[i] = '\0';
    }
    return dest;
}
