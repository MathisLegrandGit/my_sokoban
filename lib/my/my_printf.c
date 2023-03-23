/*
** EPITECH PROJECT, 2021
** my_printf
** File description:
** printf project
*/

#include "../../include/my.h"
#include <stdlib.h>
#include <stdarg.h>
#include <stdio.h>

int error_handling(char flag)
{
    if (flag != 'c' && flag != 's' && flag != 'i' &&
    flag != 'd' ) {
        return (84);
    } else {
        return (0);
    }
}

void my_printf_flags(char flag, va_list list, ...)
{
    if (flag == 'c')
        my_putchar(va_arg(list,int));
    if (flag == 's')
        my_putstr(va_arg(list, char*));
    if (flag == 'i' || flag == 'd')
        my_put_nbr(va_arg(list, int));
}

int my_printf2(int i, char *params, va_list list)
{
    char flag;

    for (i; params[i - 1] != '%'; i++){
        if (params[i] == '%') {
            flag = params[i + 1];
        } else {
            my_putchar(params[i]);
        }
    }
    if (error_handling(flag) == 84)
        return (84);
    my_printf_flags(flag, list);
    return (i);
}

int my_printf(char *params, ...)
{
    char flag;
    int i = 0;
    va_list list;

    va_start(list, params);
    for (int b = 0; params[b] != '\0'; b++) {
        if (params[b - 1] == '%') {
            i = my_printf2(i, params, list);
        }
        if (i == 84)
            return (84);
    }
    for (i++; i != my_strlen(params); i++)
        my_putchar(params[i]);
    va_end(list);
}
