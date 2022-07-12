/*
** EPITECH PROJECT, 2022
** free_array
** File description:
** free_array of type char **
*/

#include "corewar.h"

void free_array(char **array)
{
    for (int i = 0; array[i] != NULL; i++)
        free(array[i]);
    free(array);
}
