/*
** EPITECH PROJECT, 2022
** type_verificator
** File description:
** verify if the arguments of the instruction are correct
*/

#include "corewar.h"
#include "my_string.h"

int register_case(char *arg, __attribute__((unused)) korewar_t *content)
{
    char *register_array[] = {"r1", "r2", "r3", "r4", "r5", "r6", "r7", "r8",
    "r9", "r10", "r11", "r12", "r13", "r14", "r15", "r16", NULL};

    for (int i = 0; register_array[i] != NULL; i++)
        if (my_strcmp(arg, register_array[i]) == SUCCESS)
            return T_REG;
    return FAILURE;
}

int direct_case(char *arg, korewar_t *content)
{
    if (arg[0] == DIRECT_CHAR) {
        if (my_verify_content(&arg[1], "0123456789") == SUCCESS)
            return T_DIR;
    }
    if (arg[0] == DIRECT_CHAR && arg[1] == LABEL_CHAR) {
        if (my_verify_content(&arg[2], LABEL_CHARS) == SUCCESS) {
            my_put_in_indexes(&content->indexes_called, arg, content);
            return T_DIR;
        }
    }
    return FAILURE;
}

int indirect_case(char *arg, korewar_t *content)
{
    if (register_case(arg, content) != FAILURE)
        return FAILURE;
    if (register_case(arg, content) != FAILURE)
        return FAILURE;
    if (my_verify_content(arg, "0123456789") == SUCCESS)
        return T_IND;
    return FAILURE;
}
