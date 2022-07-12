/*
** EPITECH PROJECT, 2022
** my_string
** File description:
** a replica of string.h
*/

#ifndef MY_STRING_H_
    #define MY_STRING_H_

    #include "stddef.h"
    #include "stdlib.h"

char **my_str_to_word_array(char *str, char *c);
int opt_separators(char s, char *c);
int word_length(char *str, int j, char *c);
int count_word(char *str, char *c);
int my_strcmp(char *s1, char *s2);
int my_strncmp(char const *s1, char const *s2, int n);
int my_strlen(char *str);
char *my_strcpy(char *dest, char const *src);
char *my_strcat(char *dest, char *src);
char *my_strdup(char *src);
void *my_memset(void *mem, int c, size_t len);

#endif /* !MY_STRING_H_ */
