/*
** EPITECH PROJECT, 2022
** live_case
** File description:
** write the live instruction content
*/

#include "corewar.h"
#include "my_stdlib.h"

void live_case(int fd, korewar_t *content, my_op_t *node)
{
    int tmp = 0;

    if (direct_label(node->args[1]) == SUCCESS) {
        tmp = SWAP_ENDIAN_32(my_getnbr(node->args[1]));
        write(fd, &tmp, sizeof(int));
    }
    if (index_label(node->args[1]) == SUCCESS) {
        tmp = find_index(&node->args[1][2], &content->indexes);
        tmp -= node->seek;
        tmp = SWAP_ENDIAN_32(tmp);
        write(fd, &tmp, sizeof(int));
    }
}
