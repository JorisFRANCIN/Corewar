/*
** EPITECH PROJECT, 2021
** strdup
** File description:
** Duplicate the pointer in arguement
*/

#include "my_string.h"
#include <stdlib.h>

char *my_strdup(char *src)
{
    char *str = malloc(sizeof(char) * my_strlen(src) + 1);
    int i = 0;

    while (src[i] != '\0') {
        str[i] = src[i];
        i++;
    }
    str[i] = '\0';
    return (str);
}
