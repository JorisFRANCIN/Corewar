/*
** EPITECH PROJECT, 2022
** ld_case
** File description:
** write the ld instruction content
*/

#include "corewar.h"
#include "my_stdlib.h"

void ld_case(int fd, korewar_t *content, my_op_t *node)
{
    signed short int tmp = 0;
    int tmp_int = 0;
    int reg = 0;

    if (direct_label(node->args[1]) == SUCCESS) {
        tmp_int = SWAP_ENDIAN_32(my_getnbr(node->args[1]));
        write(fd, &tmp_int, sizeof(int));
    }
    if (index_label(node->args[1]) == SUCCESS) {
        tmp_int = find_index(&node->args[1][2], &content->indexes);
        tmp_int -= node->seek;
        tmp_int = SWAP_ENDIAN_32(tmp);
        write(fd, &tmp, 2);
    } else if (indirect_case(node->args[1], content) == T_IND) {
        tmp = my_getnbr(node->args[1]);
        tmp = SWAP_ENDIAN_16(tmp);
        write(fd, &tmp, 2);
    }
    reg = register_value(node->args[2]);
    write(fd, &reg, 1);
}
