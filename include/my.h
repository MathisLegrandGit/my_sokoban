/*
** EPITECH PROJECT, 2021
** my.h
** File description:
** Task02
*/

#ifndef my_h_
    #define my_h_

    void my_putchar(char c);
    int my_put_nbr(int nb);
    void my_swap(int *a, int *b);
    void my_putstr(char const *str);
    int my_strlen(char const *str);
    char *my_strcpy(char *dest, char const *src);
    char *my_strncpy(char *dest, char const *src, int n);
    char *my_strdup(char const *src);
    char *my_revstr(char *str);
    char *concat_strings(char *dest, char const *src);
    int my_strcmp(char *str, char *word);
    int intlength(int a);
    char **my_str_to_word_array(char *str, char separator);
    int my_printf(char *params, ...);

#endif
