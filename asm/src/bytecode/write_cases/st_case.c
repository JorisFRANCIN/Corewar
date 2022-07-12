/*
** EPITECH PROJECT, 2022
** st_case
** File description:
** write the st instruction content
*/

#include "corewar.h"
#include "my_stdlib.h"

void st_case(int fd, korewar_t *content, my_op_t *node)
{
    int reg = register_value(node->args[1]);
    signed short int tmp = 0;
    write(fd, &reg, 1);

    if (register_case(node->args[2], content) == T_REG) {
        reg = register_value(node->args[2]);
        write(fd, &reg, 1);
    }
    if (indirect_case(node->args[2], content) == T_IND) {
        tmp = my_getnbr(node->args[2]);
        tmp = SWAP_ENDIAN_16(tmp);
        write(fd, &tmp, 2);
    }
}
