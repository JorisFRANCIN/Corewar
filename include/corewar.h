/*
** EPITECH PROJECT, 2022
** corewar.h
** File description:
** .h file
*/

#ifndef COREWAR_H_
    #define COREWAR_H_

    #include <unistd.h>
    #include <sys/stat.h>
    #include <fcntl.h>
    #include <stdio.h>
    #include <stdlib.h>

    #include "op.h"
    #include "macro.h"
    #include "my_struct.h"

void init_content(korewar_t *content);

int file_verification(FILE *stream, korewar_t *content);
int header_parsing(char *str, korewar_t *content);
int instruction_parsing(char *str, korewar_t *content);
int valid_instruction(char *str, korewar_t *content, int index);
int verify_char_in_list(char c, char const *list);
int my_verify_content(char *str, char const *content);

int register_case(char *arg, korewar_t *content);
int indirect_case(char *arg, korewar_t *content);
int direct_case(char *arg, korewar_t *content);
int register_direct_case(char *arg, korewar_t *content);
int register_indirect_case(char *arg, korewar_t *content);
int direct_indirect_case(char *arg, korewar_t *content);
int all_case(char *arg, korewar_t *content);

int file_to_bytecode(char *filename, korewar_t *content);
int my_hex_count(korewar_t *content, int index, int *tab);
int my_put_in_indexes(index_t **list, char *arg, korewar_t *content);
int my_put_in_instruction(my_op_t **list, int *tab, int index, korewar_t *c);
int into_coding_byte(int *tab);
int find_index(char *arg, index_t **list);
int register_value(char *arg);
int index_label(char *arg);
int direct_label(char *arg);

void live_case(int fd, korewar_t *content, my_op_t *node);
void ld_case(int fd, korewar_t *content, my_op_t *node);
void st_case(int fd, korewar_t *content, my_op_t *node);
void add_case(int fd, korewar_t *content, my_op_t *node);
void sub_case(int fd, korewar_t *content, my_op_t *node);
void and_case(int fd, korewar_t *content, my_op_t *node);
void or_case(int fd, korewar_t *content, my_op_t *node);
void xor_case(int fd, korewar_t *content, my_op_t *node);
void zjmp_case(int fd, korewar_t *content, my_op_t *node);
void ldi_case(int fd, korewar_t *content, my_op_t *node);
void sti_case(int fd, korewar_t *content, my_op_t *node);
void fork_case(int fd, korewar_t *content, my_op_t *node);
void lld_case(int fd, korewar_t *content, my_op_t *node);
void lldi_case(int fd, korewar_t *content, my_op_t *node);
void lfork_case(int fd, korewar_t *content, my_op_t *node);
void aff_case(int fd, korewar_t *content, my_op_t *node);

char *my_strfill(char *str, char c, int mem_len);
int find_word_in_str(char *str, char *word);
int count_arg(char **array);
void free_array(char **array);
void free_linked_list(korewar_t *content);
void free_linked_list_help(korewar_t *content);

#endif /* !COREWAR_H_ */
