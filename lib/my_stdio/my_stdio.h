/*
** EPITECH PROJECT, 2021
** my_stdio_h
** File description:
** Replica of stdio.h
*/

#include <stdlib.h>

#ifndef MY_STDIO_H_
    #define MY_STDIO_H_

void my_putchar(char c);
void my_putstr(char const *str);
int my_put_nbr(int nb);
int my_put_unsigned_nbr(unsigned int nb);
int my_put_nbr_base(unsigned int nb, int flag2);
int my_put_nbr_hex(unsigned int nb, char flag);
int my_putstr_octal(char const *tr, int flag2);
int my_put_nbr_binary(unsigned int nb);
void *my_printf(char const *format, ...);

#endif  /* MY_STDIO_H_ */
