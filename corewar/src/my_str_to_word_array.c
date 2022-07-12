/*
** EPITECH PROJECT, 2022
** str_to_word_array
** File description:
** Transform a string into an array
*/

#include "corewar.h"
//#include "stddef.h"

int opt_separators(char s, char *c)
{
    int i = 0;
    for (i = 0; c[i] != '\0'; i++) {
        if (s == c[i])
            return 1;
    }
    return s == c[i] ? 1 : 0;
}

int word_length(char *str, int j, char *c)
{
    int length = 0;

    while (opt_separators(str[j], c) == 0) {
        if (opt_separators(str[j], c) == 0)
            length++;
        j++;
    }
    return length;
}

int count_word(char *str, char *c)
{
    int words = 0;

    for (int i = 0; str[i] != '\0'; i++) {
        if (opt_separators(str[i], c) == 1 &&
        opt_separators(str[i + 1], c) != 1)
            words++;
    }
    return words;
}

char *my_strndup(char *str, int length)
{
    char *new_str = malloc(sizeof(char) * length + 1);

    for (int i = 0; i != length; i++)
        new_str[i] = str[i];
    new_str[length] = '\0';

    return new_str;
}

char **my_str_to_word_array(char *str, char *c)
{
    int nbr_word = count_word(str, c) + 2;
    char **new_argv = malloc(sizeof(char *) * nbr_word);

    for (int i = 0, j = 0, word_len = 0; i != nbr_word - 1; j++) {
        if (opt_separators(str[j], c) == 0) {
            word_len = word_length(str, j, c);
            new_argv[i] = my_strndup(&str[j], word_len);
            j += word_len;
            i++;
        }
    }
    new_argv[nbr_word - 1] = NULL;
    return new_argv;
}
