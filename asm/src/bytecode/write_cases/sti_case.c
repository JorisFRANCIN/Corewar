/*
** EPITECH PROJECT, 2022
** sti_case
** File description:
** write the sti instruction content
*/

#include "corewar.h"
#include "my_stdlib.h"

void intermediary_function(int fd, korewar_t *content, my_op_t *node, int i)
{
    signed short int tmp = 0;
    int reg = 0;
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

void sti_case(int fd, korewar_t *content, my_op_t *node)
{
    int reg = register_value(node->args[1]);
    write(fd, &reg, 1);
    for (int i = 2; node->args[i] != NULL; i++) {
        intermediary_function(fd, content, node, i);
    }
}
