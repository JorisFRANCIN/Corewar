/*
** EPITECH PROJECT, 2022
** B-CPE-201-PAR-2-1-corewar-antoine.radice
** File description:
** sub
*/

#include "corewar.h"

int sub(info_t *info, champion_t *champ)
{
    champ->pc = (champ->pc + 2) % MEM_SIZE;
    if (info->arena.battlefield[champ->pc] <= REG_NUMBER &&
    info->arena.battlefield[champ->pc + 1] <= REG_NUMBER &&
    info->arena.battlefield[champ->pc + 2] <= REG_NUMBER)
        champ->registers[info->arena.battlefield[champ->pc + 2]] =
        champ->registers[info->arena.battlefield[champ->pc]] -
        champ->registers[info->arena.battlefield[champ->pc + 1]];
    champ->pc = (champ->pc + 3) % MEM_SIZE;
    return SUCCESS;
}
