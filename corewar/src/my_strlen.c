/*
** EPITECH PROJECT, 2022
** my_strlen
** File description:
** length of astr
*/

#include "corewar.h"

int my_strlen(char *str)
{
    int i = 0;

    while (str[i] != '\0')
        i++;
    return i;
}
