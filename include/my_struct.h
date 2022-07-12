/*
** EPITECH PROJECT, 2022
** my_struct.h
** File description:
** .h file that contains structures
*/

#ifndef MY_STRUCT_H_
    #define MY_STRUCT_H_

    #include "op.h"

typedef struct index_s {
    char *index_name;
    int seek;
    struct index_s *next;
} index_t;

typedef struct my_op_s {
    op_t op;
    int seek;
    int index;
    int size[3];
    char **args;
    unsigned char coding_byte;
    struct my_op_s *next;
} my_op_t;

typedef struct korewar_s {
    header_t header;
    my_op_t *instructions;
    index_t *indexes;
    index_t *indexes_called;
    char *tmp_line;
    int hex_count;
} korewar_t;

#endif /* !MY_STRUCT_H_ */
