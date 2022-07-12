/*
** EPITECH PROJECT, 2022
** find_word_in_str
** File description:
** Find a specific word in a string
*/

#include "corewar.h"
#include "my_string.h"

int find_word_in_str(char *str, char *word)
{
    int word_len = my_strlen(word);
    int len = my_strlen(str) - word_len;

    for (int i = 0; i != len; i++) {
        if (my_strncmp(&str[i], word, word_len) == SUCCESS)
            return SUCCESS;
    }
    return FAILURE;
}
