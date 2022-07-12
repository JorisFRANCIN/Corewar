/*
** EPITECH PROJECT, 2022
** B-CPE-201-PAR-2-1-corewar-antoine.radice
** File description:
** lfork
*/

#include "corewar.h"

champion_t *lrealloc_champ(info_t *info, int index, int offset)
{
    int i;
    champion_t *new = malloc(sizeof(champion_t) * (info->nb_champions + 1));
    for (i = 0; i <= index; i++)
        new[i] = copy_champ(&info->champions[i]);
    new[i] = copy_champ(&info->champions[i - 1]);
    for (int j = i + 1; j < (info->nb_champions + 1); j++, i++)
        new[j] = copy_champ(&info->champions[i]);
    new[index + 1].pc += offset;
    info->nb_champions += 1;
    return new;
}

int lfork(info_t *info, champion_t *champ)
{
    char nb[4];
    champ->pc = (champ->pc + 1) % MEM_SIZE;
    nb[0] = info->arena.battlefield[champ->pc];
    nb[1] = info->arena.battlefield[champ->pc + 1];
    nb[2] = 0;
    nb[3] = 0;
    info->champions = lrealloc_champ(info, get_index(info, champ),
     SWAP_ENDIAN_16(*(int*)nb));
    return SUCCESS;
}