/*
** EPITECH PROJECT, 2022
** B-CPE-201-PAR-2-1-corewar-antoine.radice
** File description:
** or
*/

#include "corewar.h"

int or(info_t *info, champion_t *champ)
{
    char code;
    char *bin;
    int nb1 = 0;
    int nb2 = 0;
    code = (champ->pc + 1) % MEM_SIZE;
    champ->pc = (champ->pc + 2) % MEM_SIZE;
    nb1 = get_type(code, champ, info);
    nb2 = get_type(code << 2, champ, info);
    if (info->arena.battlefield[champ->pc] <= REG_NUMBER)
        champ->registers[info->arena.battlefield[champ->pc]] = nb1 | nb2;
    champ->pc = (champ->pc + 1) % MEM_SIZE;
    return SUCCESS;
}