/*
** EPITECH PROJECT, 2022
** my_memset
** File description:
** copies the value of c (converted to an unsigned char)
** into each of the first n characters of the object pointed to by s.
*/

#include "my_string.h"
#include <stdio.h>

void *my_memset(void *mem, int c, size_t len)
{
    char *padding = mem;

    while (len != 0) {
        *padding++ = (char)c;
        len--;
    }
    return mem;
}
