/*
** EPITECH PROJECT, 2021
** my_put_nbr
** File description:
** yes
*/

#include "../../include/my.h"
#include <stdlib.h>

int intlength(int a)
{
    int i = 1;

    while (a > 9) {
        a = a / 10;
        i++;
    }
    return (i);
}

int my_put_nbr(int nombre1)
{
    char *intarray;
    int i = intlength(nombre1);

    intarray = malloc(sizeof(char) * i + 1);
    while (i-- > 0) {
        intarray[i] = nombre1 % 10 + '0';
        nombre1 = nombre1 / 10;
    }
    my_putstr(intarray);
    return (0);
}
