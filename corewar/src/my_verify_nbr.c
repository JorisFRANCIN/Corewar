/*
** EPITECH PROJECT, 2022
** verify_nbr
** File description:
** Verify if the string taken as parameter is an int
*/

#include "corewar.h"

int verify_char_in_list(char c, char const *list)
{
    for (int i = 0; list[i] != '\0'; i++) {
        if (c == list[i])
            return SUCCESS;
    }
    return FAILURE;
}

int my_verify_nbr(char *str)
{
    for (int i = 0; str[i] != '\0'; i++) {
        if (verify_char_in_list(str[i], "-0123456789") != SUCCESS)
            return FAILURE;
    }
    return SUCCESS;
}
