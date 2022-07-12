/*
** EPITECH PROJECT, 2022
** utils.c
** File description:
** utils
*/

#include "corewar.h"

int char_in_str(char c, char *str)
{
    for (int i = 0; str[i]; i++)
        if (str[i] == c)
            return SUCCESS;
    return FAILURE;
}

int check_all_char(char *str, char *to_check)
{
    for (int i = 0; str[i]; i++)
        if (char_in_str(str[i], to_check) == FAILURE)
            return FAILURE;
    return SUCCESS;
}

int check_cor(char *str)
{
    int i;
    for (i = my_strlen(str) - 1; i > 0 && str[i] != '.'; i--);
    if (my_strcmp(&str[i], ".cor") != 0)
        return FAILURE;
    return SUCCESS;
}

void win(info_t *info)
{
    for (int i = 0; i <= info->nb_champions; i++) {
        if (info->champions[i].number == info->last_user_live)
            my_printf("The player %i (%s) has won.\n", info->last_user_live,
            info->champions[i].header.prog_name);
        else if (info->last_user_live == 0) {
            my_printf("NO USER WON\n");
            return;
        }
    }
}