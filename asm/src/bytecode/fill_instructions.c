/*
** EPITECH PROJECT, 2022
** fill_instructions
** File description:
** fill the struct that contains the instructions
*/

#include "corewar.h"
#include "my_string.h"

void init_element(my_op_t *element, int *tab, int index, korewar_t *c)
{
    element->seek = c->hex_count;
    element->op.code = op_tab[index].code;
    element->op.mnemonique = op_tab[index].mnemonique;
    element->op.nbr_args = op_tab[index].nbr_args;
    element->index = index + 1;
    element->size[0] = tab[0];
    element->size[1] = tab[1];
    element->size[2] = tab[2];
    element->args = my_str_to_word_array(c->tmp_line, ",\n\t ");
    element->coding_byte = into_coding_byte(tab);
    element->next = NULL;
}

int my_put_in_instruction(my_op_t **list, int *tab, int index, korewar_t *c)
{
    struct my_op_s *element = malloc(sizeof(*element));
    my_op_t *last_element = NULL;
    init_element(element, tab, index, c);

    if (*list == NULL)
        *list = element;
    else {
        last_element = *list;
        while (last_element->next != NULL)
            last_element = last_element->next;
        last_element->next = element;
    }
    return (0);
}
