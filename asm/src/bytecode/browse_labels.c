/*
** EPITECH PROJECT, 2022
** browse_labels
** File description:
** Handle the part which must verify if the label is dir / ind and find the ind
*/

#include "corewar.h"
#include "my_string.h"

int find_index(char *arg, index_t **list)
{
    index_t *tmp = *list;
    char **tmp_array = NULL;

    while (tmp != NULL) {
        tmp_array = my_str_to_word_array(tmp->index_name, ":");
        if (my_strcmp(tmp_array[0], arg) == SUCCESS) {
            free_array(tmp_array);
            return tmp->seek;
        }
        tmp = tmp->next;
        free_array(tmp_array);
    }
    return SUCCESS;
}

int register_value(char *arg)
{
    char *register_array[] = {"r1", "r2", "r3", "r4", "r5", "r6", "r7", "r8",
    "r9", "r10", "r11", "r12", "r13", "r14", "r15", "r16", NULL};

    for (int i = 0; register_array[i] != NULL; i++)
        if (my_strcmp(arg, register_array[i]) == SUCCESS)
            return i + 1;
    return SUCCESS;
}

int index_label(char *arg)
{
    if (arg[0] == DIRECT_CHAR && arg[1] == LABEL_CHAR) {
        if (my_verify_content(&arg[2], LABEL_CHARS) == SUCCESS)
            return SUCCESS;
    }
    return FAILURE;
}

int direct_label(char *arg)
{
    if (arg[0] == DIRECT_CHAR) {
        if (my_verify_content(&arg[1], "0123456789") == SUCCESS)
            return SUCCESS;
    }
    return FAILURE;
}
