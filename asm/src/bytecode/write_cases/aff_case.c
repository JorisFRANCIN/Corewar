/*
** EPITECH PROJECT, 2022
** aff_case
** File description:
** write the aff instruction content
*/

#include "corewar.h"

void aff_case(int fd, __attribute__((unused))korewar_t *content, my_op_t *node)
{
    int reg = register_value(node->args[1]);

    write(fd, &reg, 1);
}
