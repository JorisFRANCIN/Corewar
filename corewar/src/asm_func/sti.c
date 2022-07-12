/*
** EPITECH PROJECT, 2022
** B-CPE-201-PAR-2-1-corewar-antoine.radice
** File description:
** sti
*/

#include "corewar.h"

int get_index_or_register(info_t *info, champion_t *champ, int code, int save)
{
    int res = 0;
    char nb[4];
    if (INDIRECT(code) == 1) {
        nb[0] = info->arena.battlefield[champ->pc % MEM_SIZE];
        nb[1] = info->arena.battlefield[champ->pc + 1 % MEM_SIZE];
        res = SWAP_ENDIAN_16(*(int*)nb);
        res = info->arena.battlefield[save + res % IDX_MOD];
        champ->pc = (champ->pc + DIR_SIZE) % MEM_SIZE;
    } else if (REGISTER(code) == 1) {
        res = champ->registers[info->arena.battlefield[champ->pc % MEM_SIZE]];
        champ->pc = (champ->pc + 1) % MEM_SIZE;
    }
    return res;
}

int sti(info_t *info, champion_t *champ)
{
    char code;
    int ret = 0;
    int nb = 0;
    int save_pc = champ->pc;
    code = info->arena.battlefield[champ->pc + 1 % MEM_SIZE] << 2;
    champ->pc = (champ->pc + 2) % MEM_SIZE;
    if (info->arena.battlefield[champ->pc % MEM_SIZE] <= REG_NUMBER)
        ret = champ->registers[info->arena.battlefield[champ->pc % MEM_SIZE]];
    nb = get_index_or_register(info, champ, code, save_pc);
    nb += get_index_or_register(info, champ, code << 2, save_pc);
    info->arena.battlefield[save_pc + nb % MEM_SIZE] = ret;
    return SUCCESS;
}
