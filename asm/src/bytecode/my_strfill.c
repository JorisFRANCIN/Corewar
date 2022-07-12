/*
** EPITECH PROJECT, 2022
** my_strfill
** File description:
** fill the part of the string that is empty with a specific char
*/

#include "corewar.h"
#include "my_string.h"

char *my_strfill(char *str, char c, int mem_len)
{
    int len = my_strlen(str);
    int i = len;

    while (i != mem_len) {
        str[i] = c;
        i++;
    }
    return str;
}
