/*
** EPITECH PROJECT, 2022
** valid_header
** File description:
** Verify if the header is valid
*/

#include "corewar.h"
#include "my_string.h"
#include "my_stdlib.h"
#include "my_stdio.h"

int valid_command(char **array_cmd, char *command)
{
    if (my_strcmp(array_cmd[0], command) != SUCCESS)
        return FAILURE;
    return SUCCESS;
}

int valid_count_arg(char **array, char **array_cmd)
{
    if (count_arg(array) != 2 || count_arg(array_cmd) != 1) {
        free_array(array);
        free_array(array_cmd);
        return FAILURE;
    }
    return SUCCESS;
}

int valid_mem(char **array, char **array_cmd, char *prog, int mem_len)
{
    int len = my_strlen(array[1]);

    if (prog[0] != '\0' || len > mem_len) {
        free_array(array);
        free_array(array_cmd);
        return FAILURE;
    }
    return SUCCESS;
}

int parsing_header_case(char *str, char *prog, int mem_len, char *command)
{
    char **array = my_str_to_word_array(str, "\"\n\t");
    char **array_cmd = my_str_to_word_array(array[0], " \t");

    if (valid_command(array_cmd, command) == SUCCESS) {
        if (valid_count_arg(array, array_cmd) == FAILURE)
            return FAILURE;
        if (valid_mem(array, array_cmd, prog, mem_len) == FAILURE)
            return FAILURE;
        my_strcpy(prog, array[1]);
        my_strfill(prog, '\0', mem_len + 1);
        free_array(array);
        free_array(array_cmd);
        return SUCCESS;
    }
    free_array(array);
    free_array(array_cmd);
    return IGNORED;
}

int header_parsing(char *str, korewar_t *content)
{
    int return_val = 0;

    if ((return_val = parsing_header_case(str, content->header.prog_name,
        PROG_NAME_LENGTH, NAME_CMD_STRING)) == FAILURE)
        return FAILURE;
    if ((return_val = parsing_header_case(str, content->header.comment,
        COMMENT_LENGTH, COMMENT_CMD_STRING)) == FAILURE)
        return FAILURE;
    return return_val;
}
