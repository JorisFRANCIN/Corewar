/*
** EPITECH PROJECT, 2022
** ldi_case
** File description:
** write the ldi instruction content
*/

#include "corewar.h"
#include "my_stdlib.h"

void ldi_index(int fd, korewar_t *content, my_op_t *node, int i)
{
    int reg = 0;
    signed short int tmp = 0;

    if (register_case(node->args[i], content) == T_REG) {
        reg = register_value(node->args[i]);
        write(fd, &reg, 1);
    } else if (direct_label(node->args[i]) == SUCCESS) {
        tmp = SWAP_ENDIAN_16(my_getnbr(node->args[i]));
        write(fd, &tmp, 2);
    }
    if (index_label(node->args[i]) == SUCCESS) {
        tmp = find_index(&node->args[i][2], &content->indexes);
        tmp -= node->seek;
        tmp = SWAP_ENDIAN_16(tmp);
        write(fd, &tmp, 2);
    } else if (indirect_case(node->args[i], content) == T_IND) {
        tmp = my_getnbr(node->args[i]);
        tmp = SWAP_ENDIAN_16(tmp);
        write(fd, &tmp, 2);
    }
}

void ldi_case(int fd, korewar_t *content, my_op_t *node)
{
    int reg = 0;

    for (int i = 1; i != 3; i++)
        ldi_index(fd, content, node, i);
    reg = register_value(node->args[3]);
    write(fd, &reg, 1);
}
