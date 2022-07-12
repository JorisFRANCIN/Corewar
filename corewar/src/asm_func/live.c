/*
** EPITECH PROJECT, 2022
** B-CPE-201-PAR-2-1-corewar-antoine.radice
** File description:
** live
*/

#include "corewar.h"

void refresh_alive(info_t *info)
{
    for (int i = 0; i < info->nb_champions; i++)
        info->champions[i].is_alive = FALSE;
}

int check_alive(info_t *info)
{
    int res = 0;
    for (int i = 0; i < info->nb_champions; i++) {
        if (info->champions[i].is_alive == TRUE)
            res++;
        else
            info->champions[i].living = FALSE;
    }
    return res;
}

int live(info_t *info, champion_t *champ)
{
    champ->pc = (champ->pc + 1) % MEM_SIZE;
    my_printf("The player %i (%s) is alive.\n", champ->number,
    champ->header.prog_name);
    champ->pc = (champ->pc + DIR_SIZE) % MEM_SIZE;
    champ->is_alive = TRUE;
    info->nb_live += 1;
    info->last_user_live = champ->number;
    return SUCCESS;
}