/*
** EPITECH PROJECT, 2022
** my_hex_count
** File description:
** count the bytes for instruction
*/

#include "corewar.h"

int case_one(int *tab, korewar_t *content)
{
    content->hex_count += 2;

    for (int i = 0; tab[i]; i++) {
        content->hex_count += tab[i] == T_DIR ? 2 : 0;
        content->hex_count += tab[i] == T_REG ? 1 : 0;
        content->hex_count += tab[i] == T_IND ? 2 : 0;
    }
    return SUCCESS;
}

int case_two(int *tab, korewar_t *content)
{
    content->hex_count += 2;

    for (int i = 0; tab[i]; i++) {
        content->hex_count += tab[i] == T_DIR ? 4 : 0;
        content->hex_count += tab[i] == T_REG ? 1 : 0;
        content->hex_count += tab[i] == T_IND ? 2 : 0;
    }
    return SUCCESS;
}

int my_hex_count(korewar_t *content, int index, int *tab)
{
    int type = op_tab[index].code;

    if (type == 1 || type == 4 || type == 5)
        content->hex_count += 5;
    if (type == 9 || type == 12 || type == 15 || type == 16)
        content->hex_count += 3;
    if (type == 3 || type == 10 || type == 11 || type == 14)
        case_one(tab, content);
    if (type == 2 || type == 6 || type == 7 || type == 8 || type == 13)
        case_two(tab, content);
    return SUCCESS;
}
