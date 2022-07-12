/*
** EPITECH PROJECT, 2022
** init_content
** File description:
** init the structure korewar_t
*/

#include "corewar.h"
#include "my_string.h"
#include "my_stdio.h"
#include <string.h>

void init_content(korewar_t *content)
{
    content->indexes = NULL;
    content->indexes_called = NULL;
    content->instructions = NULL;
    content->tmp_line = NULL;
    content->hex_count = 0;
    my_memset(&content->header, 0, sizeof(header_t));
    content->header.prog_size = 0;
    content->header.magic = 0xf383ea00;
    content->header.prog_name[0] = '\0';
    content->header.comment[0] = '\0';
    content->header.prog_size = 0;
}
