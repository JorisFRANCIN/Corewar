/*
** EPITECH PROJECT, 2022
** B-CPE-201-PAR-2-1-corewar-antoine.radice
** File description:
** st
*/

#include "corewar.h"

int st(info_t *info, champion_t *champ)
{
    char code;
    int ret = 0;
    int res = 0;
    char nb[4];
    code = info->arena.battlefield[champ->pc + 1 % MEM_SIZE] << 2;
    if (info->arena.battlefield[champ->pc + 2 % MEM_SIZE] <= REG_NUMBER)
        ret = champ->registers
        [info->arena.battlefield[champ->pc + 2 % MEM_SIZE]];
    if (DIRECT(code) == 1) {
        for (int i = 0; i < 4; i++)
            nb[i] = info->arena.battlefield[champ->pc + 3 + i % MEM_SIZE];
        res = SWAP_ENDIAN(*(int*)nb);
        info->arena.battlefield[champ->pc + res % IDX_MOD] = ret;
        champ->pc = (champ->pc + 3 + DIR_SIZE) % MEM_SIZE;
    } else if (REGISTER(code) == 1) {
        champ->registers[info->arena.battlefield
        [champ->pc + 3 % MEM_SIZE]] = ret;
        champ->pc = (champ->pc + 4) % MEM_SIZE;
    }
    return SUCCESS;
}
