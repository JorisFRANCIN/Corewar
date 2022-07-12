/*
** EPITECH PROJECT, 2022
** B-CPE-201-PAR-2-1-corewar-antoine.radice
** File description:
** lld
*/

#include "corewar.h"

int lld(info_t *info, champion_t *champ)
{
    char code;
    int ind_or_dir;
    code = (champ->pc + 1) % MEM_SIZE;
    champ->pc = (champ->pc + 2) % MEM_SIZE;
    ind_or_dir = get_type(code, champ, info);
    if (INDIRECT(code) == 1)
        if (info->arena.battlefield[champ->pc] <= REG_NUMBER)
            champ->registers[info->arena.battlefield[champ->pc]] =
            info->arena.battlefield[(champ->pc + ind_or_dir) % MEM_SIZE];
    else if (DIRECT(code) == 1)
        if (info->arena.battlefield[champ->pc] <= REG_NUMBER)
            champ->registers[info->arena.battlefield[champ->pc]] = ind_or_dir;
    champ->pc = (champ->pc + 1) % MEM_SIZE;
    return SUCCESS;
}