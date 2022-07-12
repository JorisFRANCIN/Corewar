/*
** EPITECH PROJECT, 2021
** strncmp
** File description:
** description
*/

#include "my_string.h"

int my_strncmp(char const *s1, char const *s2, int n)
{
    int count = 0;
    int i = 0;

    for (; i != n && s1[i] != '\0' && s2[i] != '\0'; i++)
        count += s1[i] - s2[i];
    return count;
}
