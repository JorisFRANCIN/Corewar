/*
** EPITECH PROJECT, 2021
** strcpy
** File description:
** description
*/

#include "my_string.h"

char *my_strcpy(char *dest, char const *src)
{
    int tmp = 0;

    for (int i = 0; src[i] != '\0'; i++) {
        dest[i] = src[i];
        tmp += 1;
    }
    dest[tmp] = '\0';
    return (dest);
}
