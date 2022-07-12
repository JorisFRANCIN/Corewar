/*
** EPITECH PROJECT, 2022
** assembler
** File description:
** generates binary programs that the virtual machine can execute
*/

#include "corewar.h"
#include "my_stdio.h"
#include "my_string.h"

int valid_name_format(char *filepath)
{
    char **tmp = NULL;
    int check = 0;

    for (int i = 0; filepath[i] != '\0'; i++)
        if (filepath[i] == '.')
            check = 1;
    if (check != 1)
        return FAILURE;
    tmp = my_str_to_word_array(filepath, ".");
    if (count_arg(tmp) == 2) {
        if (my_strcmp(tmp[1], "s") != SUCCESS) {
            free_array(tmp);
            return FAILURE;
        }
    }
    free_array(tmp);
    return SUCCESS;
}

int check_error(FILE *stream, korewar_t *content)
{
    if (stream == NULL)
        return FAILURE;
    if (file_verification(stream, content) == FAILURE)
        return FAILURE;
    return SUCCESS;
}

int display_help(void)
{
    my_printf("USAGE\n"
    "./asm file_name[.s]\n"
    "DESCRIPTION\n"
    "file_name file in assembly language to be "
    "converted into file_name.cor, an\n"
    "executable in the Virtual Machine.\n");

    return SUCCESS;
}

int main(int argc, char **argv)
{
    FILE *file;
    korewar_t content;
    init_content(&content);

    if (argc == 2) {
        if (my_strcmp(argv[1], "-h") == SUCCESS)
            return display_help();
        if (valid_name_format(argv[1]) == FAILURE)
            return ERROR_ARG;
        file = fopen(argv[1], "r");
        if (check_error(file, &content) == FAILURE)
            return ERROR_ARG;
        file_to_bytecode(argv[1], &content);
        fclose(file);
        free_linked_list(&content);
        return SUCCESS;
    }
    return ERROR_ARG;
}
