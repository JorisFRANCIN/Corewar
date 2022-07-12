/*
** EPITECH PROJECT, 2022
** indexes_handler
** File description:
** Manage the linked list that contains the indexes
*/

#include "corewar.h"
#include "my_string.h"

int my_put_in_indexes(index_t **list, char *arg, korewar_t *content)
{
    struct index_s *element;
    index_t *last_element = NULL;

    element = malloc(sizeof(*element));
    element->index_name = my_strdup(arg);
    element->seek = content->hex_count;
    element->next = NULL;

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
