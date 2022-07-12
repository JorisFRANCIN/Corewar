/*
** EPITECH PROJECT, 2022
** sub_case
** File description:
** write the sub instruction content
*/

#include "corewar.h"

void sub_case(int fd, korewar_t *content, my_op_t *node)
{
    int reg = 0;

    for (int i = 1; node->args[i] != NULL; i++) {
        if (register_case(node->args[i], content) == T_REG) {
            reg = register_value(node->args[i]);
            write(fd, &reg, 1);
        }
    }
}
