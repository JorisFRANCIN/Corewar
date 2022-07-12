/*
** EPITECH PROJECT, 2022
** corewar
** File description:
** vm
*/

#include "corewar.h"

int read_champions(char *path, champion_t *champion)
{
    size_t r = 0;
    int fd = open(path, O_RDONLY);
    if (fd < 0)
        return FAILURE;
    if ((r = read(fd, &champion->header, sizeof(header_t))) <= 0)
        return FAILURE;
    champion->header.magic = SWAP_ENDIAN(champion->header.magic);
    champion->header.prog_size = SWAP_ENDIAN(champion->header.prog_size);
    champion->is_alive = FALSE;
    champion->living = TRUE;
    champion->is_waiting = FALSE;
    champion->wait = 0;
    champion->code = malloc(sizeof(champion->code) *
    champion->header.prog_size);
    if ((r = read(fd, champion->code, champion->header.prog_size)) <
    champion->header.prog_size)
        return FAILURE;
    return SUCCESS;
}

int handle_arg_champion(char **av, champion_t *champ, int ac, int i)
{
    if (my_strcmp(av[i], "-n") == 0 && i + 1 < ac) {
        if (check_all_char(av[i + 1], "0123456789") == FAILURE)
            return -1;
        champ->number = my_atoi(av[++i]);
        i++;
    }
    if (my_strcmp(av[i], "-a") == 0 && i + 1 < ac) {
        if (check_all_char(av[i + 1], "0123456789") == FAILURE)
            return -1;
        champ->load_adress = my_atoi(av[++i]);
        i++;
    }
    if (check_cor(av[i]) == FAILURE)
        return -1;
    champ->registers[1] = champ->number;
    if (read_champions(av[i], champ) == FAILURE)
        return -1;
    return i;
}

int handle_arg(int ac, char **av, info_t *info)
{
    int i = 1;
    if (ac > 2 && my_strcmp(av[1], "-dump") == 0 && check_all_char(av[2],
    "0123456789") == SUCCESS) {
        i = 3;
        info->dump = my_atoi(av[2]);
    }
    for (int j = 0; i < ac; i++, j++) {
        i = handle_arg_champion(av, &info->champions[j], ac , i);
        if (i == -1)
            return FAILURE;
    }
    return SUCCESS;
}

int init_info(int ac, char **av, info_t *info)
{
    info->dump = 0;
    info->nb_live = 0;
    info->last_user_live = 0;
    info->nb_champions = 0;
    for (int j = 1; j < ac; j++)
        if (check_cor(av[j]) == SUCCESS)
            info->nb_champions++;
    info->champions = malloc(sizeof(champion_t) * info->nb_champions);
    for (int i = 0; i < info->nb_champions; i++) {
        info->champions[i].number = i + 1;
        info->champions[i].carry = 0;
        info->champions[i].load_adress = 0;
        info->champions[i].pc = 0;
        for (int j = 0; j < REG_NUMBER; j++)
            info->champions[i].registers[j] = 0;
    }
    return SUCCESS;
}

int main(int ac, char **av)
{
    info_t info;
    if (ac == 2 && my_strcmp(av[1], "-h") == 0)
        write(1, "USAGE\n./corewar [-dump nbr_cycle] [[-n prog_number]"
        " [-a load_address] prog_name] ...\nDESCRIPTION\n-dump nbr_cycle "
        "dumps the memory after the nbr_cycle execution (if the round isn’t"
        "\nalready over) with the following format: 32 bytes/line\nin "
        "hexadecimal (A0BCDEFE1DD3...)\n-n prog_number sets the next "
        "program’s number. By default, the first free number\nin the "
        "parameter order\n-a load_address sets the next program’s loading"
        " address. When no address is\nspecified, optimize the addresses so"
        " that the processes are as far\naway from each other as possible. "
        "The addresses are MEM_SIZE modulo.", 590);
    if (ac < 3 || init_info(ac, av, &info) == FAILURE ||
    handle_arg(ac, av, &info) == FAILURE)
        return 84;
    if (init_arena(&info) == FAILURE)
        return 84;
    loop(&info);
    return 0;
}
