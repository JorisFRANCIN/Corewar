/*
** EPITECH PROJECT, 2022
** B-CPE-201-PAR-2-1-corewar-antoine.radice
** File description:
** aff
*/

#include "corewar.h"

int aff(info_t *info, champion_t *champ)
{
    char c;
    champ->pc = (champ->pc + 2) % MEM_SIZE;
    if (info->arena.battlefield[champ->pc] <= REG_NUMBER) {
        c = champ->registers[info->arena.battlefield[champ->pc]] % 256;
        write(1, &c, 1);
    }
    champ->pc = (champ->pc + 1) % MEM_SIZE;
    return SUCCESS;
}
