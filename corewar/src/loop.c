/*
** EPITECH PROJECT, 2022
** B-CPE-201-PAR-2-1-corewar-antoine.radice
** File description:
** loop
*/

#include "corewar.h"

static int (*const opcode_to_func[])(info_t*, champion_t*) =
{
    &live,
    &ld,
    &st,
    &add,
    &sub,
    &and,
    &or,
    &xor,
    &zjump,
    &ldi,
    &sti,
    &fork_f,
    &lld,
    &lldi,
    &lfork,
    &aff
};

void print_hexarena(info_t *info)
{
    for (int i = 0; i < MEM_SIZE; i++) {
        if (i % 32 == 0 && i > 0) {
            my_printf("\n");
        }
        my_printf(info->arena.battlefield[i] == 0 ? "0 " : "%X ",
        (int)info->arena.battlefield[i]);
    }
    my_printf("\n");
}

void exec_action(info_t *info, champion_t *champ)
{
    if ((info->arena.battlefield[champ->pc % MEM_SIZE] >= 0 &&
    info->arena.battlefield[champ->pc % MEM_SIZE] <= 15) && champ->living ==
    TRUE && info->arena.user_id[champ->pc % MEM_SIZE] == champ->number) {
        champ->is_waiting = FALSE;
        opcode_to_func
        [info->arena.battlefield[champ->pc % MEM_SIZE] - 1](info, champ);
    } else if (champ->living == TRUE)
        champ->pc = (champ->pc + 1) % MEM_SIZE;
}

int turn(info_t *info)
{
    for (int i = 0; i < info->nb_champions; i++) {
        if (info->champions[i].is_waiting == FALSE &&
        info->arena.battlefield[info->champions[i].pc % MEM_SIZE] > 0 &&
        info->arena.battlefield[info->champions[i].pc % MEM_SIZE] <= 16) {
            info->champions[i].is_waiting = TRUE;
            info->champions[i].wait = op_tab[info->arena.battlefield
            [info->champions[i].pc % MEM_SIZE]].nbr_cycles;
        } else if (info->champions[i].is_waiting == TRUE &&
        info->champions[i].wait == 0 && info->champions[i].living == TRUE) {
            exec_action(info, &info->champions[i]);
        } else
            info->champions[i].wait--;
    }
}

void loop(info_t *info)
{
    int decrement = 1;
    while (info->arena.cycle_to_die > 0) {
        info->arena.cycle = 0;
        while (info->arena.cycle <= info->arena.cycle_to_die) {
            if (info->dump > 0 && info->arena.cycle >= info->dump)
                print_hexarena(info);
            if (info->nb_live >= NBR_LIVE && check_alive(info) ==
            info->nb_champions) {
                info->arena.cycle_to_die -= (CYCLE_DELTA * decrement++);
                info->nb_live = 0;
            }
            turn(info);
            info->arena.cycle++;
        }
        if (check_alive(info) <= 1) {
            win(info);
            exit(0);
        }
        refresh_alive(info);
    }
}
