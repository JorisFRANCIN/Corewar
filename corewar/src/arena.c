/*
** EPITECH PROJECT, 2022
** B-CPE-201-PAR-2-1-corewar-antoine.radice
** File description:
** arena
*/

#include "corewar.h"

void print_arena(info_t *info)
{
    int tmp = -1;
    for (int i = 0; i < MEM_SIZE; i++) {
        my_printf(info->arena.user_id[i] == 0 ? "\e[30m%X\e[0m " :
        info->arena.user_id[i] == 1 ? BLUE_BG: info->arena.user_id[i] == 2
        ? RED_BG: info->arena.user_id[i] == 3 ? YELLOW_BG : GREEN_BG,
        info->arena.battlefield[i]);
        if (i == tmp + 32) {
            tmp = i;
            my_printf("\n");
        }
    }
    my_printf("\n");
}

int set_arena(info_t *info)
{
    int i = 0;
    int j = 0;

    while (i < info->nb_champions) {
        j = 0;
        while (j < info->champions[i].header.prog_size) {
            if (info->arena.battlefield
            [info->champions[i].load_adress + j] == 0) {
                info->champions[i].pc = info->champions[i].load_adress;
                info->arena.battlefield[info->champions[i].load_adress + j] =
                info->champions[i].code[j];
            } else
                return FAILURE;
            info->arena.user_id[info->champions[i].load_adress + j] = i + 1;
            j++;
        }
        i++;
    }
    return SUCCESS;
}

int init_arena(info_t *info)
{
    info->arena.user_id = malloc(sizeof(int) * MEM_SIZE);
    info->arena.battlefield = malloc(sizeof(char) * MEM_SIZE);
    info->arena.cycle = 0;
    for (int i = 0; i < MEM_SIZE; i++) {
        info->arena.battlefield[i] = '\0';
        info->arena.user_id[i] = 0;
    }
    if (set_arena(info) == FAILURE) {
        write(2, "adress conflict\n", 17);
        return FAILURE;
    }
    info->arena.cycle_to_die = CYCLE_TO_DIE - info->dump;
    print_arena(info);
    print_hexarena(info);
    return SUCCESS;
}
