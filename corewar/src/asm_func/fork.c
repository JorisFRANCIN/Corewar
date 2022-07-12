/*
** EPITECH PROJECT, 2022
** B-CPE-201-PAR-2-1-corewar-antoine.radice
** File description:
** fork
*/

#include "corewar.h"

champion_t copy_champ(champion_t *champ)
{
    champion_t new;
    new.number = champ->number;
    new.load_adress = champ->load_adress;
    for (int i = 0; i < REG_NUMBER + 1; i++)
        new.registers[i] = champ->registers[i];
    new.pc = champ->pc;
    new.carry = champ->carry;
    new.is_alive = champ->is_alive;
    new.living = champ->living;
    new.is_waiting = champ->is_waiting;
    new.code = champ->code;
    new.header = champ->header;
    return new;
}

champion_t *realloc_champ(info_t *info, int index, int offset)
{
    int i;
    champion_t *new = malloc(sizeof(champion_t) * (info->nb_champions + 1));
    for (i = 0; i <= index; i++)
        new[i] = copy_champ(&info->champions[i]);
    new[i] = copy_champ(&info->champions[i - 1]);
    for (int j = i + 1; j < (info->nb_champions + 1); j++, i++)
        new[j] = copy_champ(&info->champions[i]);
    new[index + 1].pc += offset % IDX_MOD;
    info->nb_champions += 1;
    return new;
}

int get_index(info_t *info, champion_t *champ)
{
    int i;

    for (int i = 0; i < info->nb_champions; i++)
        if (info->champions[i].number == champ->number)
            return i;
    return 0;
}

int fork_f(info_t *info, champion_t *champ)
{
    char nb[4];
    champ->pc = (champ->pc + 1) % MEM_SIZE;
    nb[0] = info->arena.battlefield[champ->pc];
    nb[1] = info->arena.battlefield[champ->pc + 1];
    nb[2] = 0;
    nb[3] = 0;
    info->champions = realloc_champ(info, get_index(info, champ),
    SWAP_ENDIAN_16(*(int*)nb));
    return SUCCESS;
}