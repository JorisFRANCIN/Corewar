/*
** EPITECH PROJECT, 2022
** count_arg
** File description:
** argc of a char **
*/

#include "corewar.h"

int count_arg(char **array)
{
    int i = 0;

    while (array[i] != NULL)
        i++;
    return i;
}
