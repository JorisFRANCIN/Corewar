/*
** EPITECH PROJECT, 2022
** valid_instruction
** File description:
** verify if the line concerned is a valid instruction
*/

#include "corewar.h"
#include "my_string.h"
#include "my_stdlib.h"
#include "my_stdio.h"

int verify_arg(char *arg, int type, korewar_t *content)
{
    int (*verify_type[7])(char *arg, korewar_t *content);
    int val = 0;

    verify_type[0] = register_case;
    verify_type[1] = direct_case;
    verify_type[2] = register_direct_case;
    verify_type[3] = indirect_case;
    verify_type[4] = register_indirect_case;
    verify_type[5] = direct_indirect_case;
    verify_type[6] = all_case;

    val = verify_type[type - 1](arg, content);
    return val;
}

int valid_arg(char **instruction, int index, korewar_t *content)
{
    int type_val[MAX_ARGS_NUMBER] = {0, 0, 0, 0};

    for (int i = 0; i != op_tab[index].nbr_args; i++) {
        if ((type_val[i] = verify_arg(instruction[i + 1],
        op_tab[index].type[i], content)) == FAILURE)
            return FAILURE;
    }
    my_put_in_instruction(&content->instructions, type_val, index, content);
    my_hex_count(content, index, type_val);
    return SUCCESS;
}

int valid_instruction(char *str, korewar_t *content, int index)
{
    char **instructions = my_str_to_word_array(str, ",\n\t ");

    if (count_arg(instructions) - 1 != op_tab[index].nbr_args) {
        free_array(instructions);
        return FAILURE;
    }
    content->tmp_line = str;
    if (valid_arg(instructions, index, content) == FAILURE) {
        free_array(instructions);
        return FAILURE;
    }
    free_array(instructions);
    return SUCCESS;
}

int instruction_parsing(char *str, korewar_t *content)
{
    char **array = my_str_to_word_array(str, " \t\n");
    int return_val = 0;

    for (int i = 0; op_tab[i].mnemonique != 0; i++) {
        if (my_strcmp(array[0], op_tab[i].mnemonique) == SUCCESS) {
            return_val = valid_instruction(str, content, i);
            free_array(array);
            return return_val;
        }
    }
    my_put_in_indexes(&content->indexes, array[0], content);
    if (count_arg(array) > 1)
        instruction_parsing(&str[my_strlen(array[0])], content);
    free_array(array);
    return SUCCESS;
}
