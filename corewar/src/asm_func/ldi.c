/*
** EPITECH PROJECT, 2022
** B-CPE-201-PAR-2-1-corewar-antoine.radice
** File description:
** ldi
*/

#include "corewar.h"

int ldi(info_t *info, champion_t *champ)
{
    int nb[4];
    int arg1;
    int arg2;
    int reg;
    for (int i = 0; i < 4; i++)
        nb[i] = 0;
    champ->pc = (champ->pc + 2) % MEM_SIZE;
    nb[0] = info->arena.battlefield[champ->pc % MEM_SIZE];
    nb[1] = info->arena.battlefield[champ->pc + 1 % MEM_SIZE];
    arg1 = SWAP_ENDIAN_16(*(int*)nb);
    champ->pc = (champ->pc + IND_SIZE) % MEM_SIZE;
    nb[0] = info->arena.battlefield[champ->pc % MEM_SIZE];
    nb[1] = info->arena.battlefield[champ->pc + 1 % MEM_SIZE];
    arg2 = SWAP_ENDIAN_16(*(int*)nb);
    champ->pc = (champ->pc + IND_SIZE) % MEM_SIZE;
    reg = champ->registers[info->arena.battlefield[champ->pc]];
    champ->pc = (champ->pc + 1) % MEM_SIZE;
    arg1 = info->arena.battlefield[(champ->pc + arg1) % IDX_MOD] + 4;
    champ->registers[reg] = (champ->pc + arg1) % IDX_MOD;
    return SUCCESS;
}