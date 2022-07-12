/*
** EPITECH PROJECT, 2022
** file_to_bytecode
** File description:
** Interpret te file content to the VM into 2-unit bytecodes
*/

#include "corewar.h"
#include "my_string.h"
#include "my_stdlib.h"

int write_args(int fd, korewar_t *content, my_op_t *node)
{
    void (*write_it[16])(int fd, korewar_t *content, my_op_t *node);

    write_it[0] = live_case;
    write_it[1] = ld_case;
    write_it[2] = st_case;
    write_it[3] = add_case;
    write_it[4] = sub_case;
    write_it[5] = and_case;
    write_it[6] = or_case;
    write_it[7] = xor_case;
    write_it[8] = zjmp_case;
    write_it[9] = ldi_case;
    write_it[10] = sti_case;
    write_it[11] = fork_case;
    write_it[12] = lld_case;
    write_it[13] = lldi_case;
    write_it[14] = lfork_case;
    write_it[15] = aff_case;
    write_it[node->index - 1](fd, content, node);
    return SUCCESS;
}

void write_current_instruction(int fd, korewar_t *content, my_op_t *node)
{
    int index = node->op.code;
    write(fd, &node->op.code, 1);
    if (index != 1 && index != 9 && index != 12 && index != 15)
        write(fd, &node->coding_byte, 1);
    write_args(fd, content, node);
}

void read_struct_content(int fd, korewar_t *content, my_op_t **list)
{
    my_op_t *tmp = *list;

    while (tmp != NULL) {
        write_current_instruction(fd, content, tmp);
        tmp = tmp->next;
    }
}

int file_to_bytecode(char *filename, korewar_t *content)
{
    char **tmp_array = my_str_to_word_array(filename, "/.");
    int index = count_arg(tmp_array);
    char *new_filename = my_strcat(tmp_array[index - 2], ".cor");
    int fd = open(new_filename, O_CREAT | O_TRUNC | O_RDWR, 0664);

    write(fd, &content->header, sizeof(header_t));
    read_struct_content(fd, content, &content->instructions);

    free_array(tmp_array);
    free(new_filename);
    close(fd);
    return SUCCESS;
}
