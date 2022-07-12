/*
** EPITECH PROJECT, 2022
** and_case
** File description:
** write the and instruction content
*/

#include "corewar.h"
#include "my_stdlib.h"

void and_index(int fd, korewar_t *content, my_op_t *node, int i)
{
    signed short int tmp = 0;
    int tmp_int = 0;
    int reg = 0;
    if (register_case(node->args[i], content) == T_REG) {
        reg = register_value(node->args[i]);
        write(fd, &reg, 1);
    } else if (direct_label(node->args[i]) == SUCCESS) {
        tmp_int = SWAP_ENDIAN_32(my_getnbr(node->args[i]));
        write(fd, &tmp_int, sizeof(int));
    }
    if (index_label(node->args[i]) == SUCCESS) {
        tmp_int = find_index(&node->args[i][2], &content->indexes);
        tmp_int -= node->seek;
        tmp_int = SWAP_ENDIAN_32(tmp_int);
        write(fd, &tmp_int, sizeof(int));
    } else if (indirect_case(node->args[i], content) == T_IND) {
        tmp = my_getnbr(node->args[i]);
        tmp = SWAP_ENDIAN_16(tmp);
        write(fd, &tmp, 2);
    }
}

void and_case(int fd, korewar_t *content, my_op_t *node)
{
    int reg = 0;

    for (int i = 1; i != 3; i++)
        and_index(fd, content, node, i);
    reg = register_value(node->args[3]);
    write(fd, &reg, 1);
}
