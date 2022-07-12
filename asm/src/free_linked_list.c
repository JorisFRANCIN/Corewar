/*
** EPITECH PROJECT, 2022
** free_linked_list
** File description:
** free all nodes of a linked_list
*/

#include "corewar.h"

void free_linked_list_help(korewar_t *content)
{
    index_t *tmp3;

    while (content->indexes_called != NULL) {
        tmp3 = content->indexes_called;
        content->indexes_called = content->indexes_called->next;
        free(tmp3->index_name);
        free(tmp3);
    }
}

void free_linked_list(korewar_t *content)
{
    my_op_t *tmp;
    index_t *tmp2;

    while (content->instructions != NULL) {
        tmp = content->instructions;
        content->instructions = content->instructions->next;
        free_array(tmp->args);
        free(tmp);
    }
    while (content->indexes != NULL) {
        tmp2 = content->indexes;
        content->indexes = content->indexes->next;
        free(tmp2->index_name);
        free(tmp2);
    }
    free_linked_list_help(content);
}
