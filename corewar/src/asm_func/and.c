/*
** EPITECH PROJECT, 2022
** B-CPE-201-PAR-2-1-corewar-antoine.radice
** File description:
** and
*/

#include "corewar.h"

int get_type(char code, champion_t *champ, info_t *info)
{
    int res = 0;
    char nb[4];
    for (int i = 0; i < 4; i++)
        nb[i] = 0;
    if (INDIRECT(code) == 1) {
        nb[0] = info->arena.battlefield[champ->pc % MEM_SIZE];
        nb[1] = info->arena.battlefield[champ->pc + 1 % MEM_SIZE];
        res = SWAP_ENDIAN_16(*(int*)nb);
        res = info->arena.battlefield[champ->pc + res];
        champ->pc = (champ->pc + IND_SIZE) % MEM_SIZE;
    } else if (DIRECT(code) == 1) {
        for (int i = 0; i < 4; i++)
            nb[i] = info->arena.battlefield[champ->pc + i % MEM_SIZE];
        res = SWAP_ENDIAN(*(int*)nb);
        champ->pc = (champ->pc + DIR_SIZE) % MEM_SIZE;
    } else if (REGISTER(code) == 1) {
        res = champ->registers[info->arena.battlefield[champ->pc]];
        champ->pc = (champ->pc + 1) % MEM_SIZE;
    }
    return res;
}

int and(info_t *info, champion_t *champ)
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
        champ->registers[info->arena.battlefield[champ->pc]] = nb1 & nb2;
    champ->pc = (champ->pc + 1) % MEM_SIZE;
    return SUCCESS;
}
