/*
** EPITECH PROJECT, 2022
** B-CPE-201-PAR-2-1-corewar-antoine.radice
** File description:
** add
*/

#include "corewar.h"

int add(info_t *info, champion_t *champ)
{
    champ->pc = (champ->pc + 2) % MEM_SIZE;
    if (info->arena.battlefield[champ->pc] <= REG_NUMBER &&
    info->arena.battlefield[champ->pc + 1] <= REG_NUMBER &&
    info->arena.battlefield[champ->pc + 2] <= REG_NUMBER)
        champ->registers[info->arena.battlefield[champ->pc + 2]] =
        champ->registers[info->arena.battlefield[champ->pc + 1]] +
        champ->registers[info->arena.battlefield[champ->pc]];
    champ->pc = (champ->pc + 3) % MEM_SIZE;
    return SUCCESS;
}