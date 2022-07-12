/*
** EPITECH PROJECT, 2022
** fork_case
** File description:
** write the fork instruction content
*/

#include "corewar.h"
#include "my_stdlib.h"

void fork_case(int fd, korewar_t *content, my_op_t *node)
{
    signed short tmp = 0;

    if (direct_label(node->args[1]) == SUCCESS) {
        tmp = SWAP_ENDIAN_16(my_getnbr(node->args[1]));
        write(fd, &tmp, 2);
    }
    if (index_label(node->args[1]) == SUCCESS) {
        tmp = find_index(&node->args[1][2], &content->indexes);
        tmp -= node->seek;
        tmp = SWAP_ENDIAN_16(tmp);
        write(fd, &tmp, 2);
    }
}
