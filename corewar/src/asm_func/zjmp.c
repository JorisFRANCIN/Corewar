/*
** EPITECH PROJECT, 2022
** B-CPE-201-PAR-2-1-corewar-antoine.radice
** File description:
** zjmp
*/

#include "corewar.h"

int zjump(info_t *info, champion_t *champ)
{
    int res = 0;
    char nb[4];
    nb[0] = info->arena.battlefield[champ->pc + 1 % MEM_SIZE];
    nb[1] = info->arena.battlefield[champ->pc + 2 % MEM_SIZE];
    nb[2] = 0;
    nb[3] = 0;
    res = SWAP_ENDIAN_16(*(int*)nb);
    champ->pc = (champ->pc + 3 + (res % IDX_MOD)) % MEM_SIZE;
    return SUCCESS;
}