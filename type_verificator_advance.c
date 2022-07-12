/*
** EPITECH PROJECT, 2022
** type_verificator
** File description:
** verify if the arg, contentuments of the instruction are correct
*/

#include "corewar.h"

int register_direct_case(char *arg, korewar_t *content)
{
    if (register_case(arg, content) != FAILURE)
        return T_REG;
    if (direct_case(arg, content) != FAILURE)
        return T_DIR;
    return FAILURE;
}

int register_indirect_case(char *arg, korewar_t *content)
{
    if (register_case(arg, content) != FAILURE)
        return T_REG;
    if (indirect_case(arg, content) != FAILURE)
        return T_IND;
    return FAILURE;
}

int direct_indirect_case(char *arg, korewar_t *content)
{
    if (direct_case(arg, content) != FAILURE)
        return T_DIR;
    else if (indirect_case(arg, content) != FAILURE)
        return T_IND;
    return FAILURE;
}

int all_case(char *arg, korewar_t *content)
{
    if (register_case(arg, content) != FAILURE)
        return T_REG;
    if (direct_case(arg, content) != FAILURE)
        return T_DIR;
    if (indirect_case(arg, content) != FAILURE)
        return T_IND;
    return FAILURE;
}
