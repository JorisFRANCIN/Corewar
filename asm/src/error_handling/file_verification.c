/*
** EPITECH PROJECT, 2022
** file_to_bytecode
** File description:
** verify a file content to the VM
*/

#include "corewar.h"
#include "my_stdio.h"
#include "my_string.h"

int index_in_dict(char *index_called, index_t *tmp_dict)
{
    char **index = NULL;

    while (tmp_dict != NULL) {
        index = my_str_to_word_array(tmp_dict->index_name, ":");
        if (my_strcmp(index[0], index_called) == SUCCESS) {
            free_array(index);
            return SUCCESS;
        }
        free_array(index);
        tmp_dict = tmp_dict->next;
    }
    return FAILURE;
}

int file_defined(index_t **dict, index_t **list)
{
    index_t *tmp_list = *list;
    index_t *tmp_dict = *dict;
    char **index_called = NULL;

    while (tmp_list != NULL) {
        tmp_dict = *dict;
        index_called = my_str_to_word_array(tmp_list->index_name, ":%%");
        if (index_in_dict(index_called[0], tmp_dict) == FAILURE) {
            free_array(index_called);
            return FAILURE;
        }
        tmp_list = tmp_list->next;
        free_array(index_called);
    }
    return SUCCESS;
}

int read_line(char *line_buffer, korewar_t *content)
{
    if (line_buffer[0] == '\n' || line_buffer[0] == '#')
        return SUCCESS;
    if (header_parsing(line_buffer, content) == FAILURE)
        return FAILURE;
    else if (header_parsing(line_buffer, content) == IGNORED)
        return instruction_parsing(line_buffer, content);
    if (my_strlen(content->header.prog_name) +
    my_strlen(content->header.comment) > MEM_SIZE)
        return FAILURE;
    return SUCCESS;
}

int optionnal_error_message(FILE *stream,
char *current_line_buffer, korewar_t *content)
{
    write(2, ERROR_MSG, sizeof(ERROR_MSG));
    free(current_line_buffer);
    free_linked_list(content);
    fclose(stream);

    return FAILURE;
}

int file_verification(FILE *stream, korewar_t *content)
{
    size_t n = 0;
    char *tmp = NULL;

    while (getline(&tmp, &n, stream) != -1) {
        if (read_line(tmp, content) == FAILURE)
            return optionnal_error_message(stream, tmp, content);
    }
    content->header.prog_size = SWAP_ENDIAN_32(content->hex_count);
    if (file_defined(&content->indexes, &content->indexes_called) != SUCCESS)
        return optionnal_error_message(stream, tmp, content);
    if (content->header.prog_name[0] == '\0'
    || content->header.comment[0] == '\0')
        return optionnal_error_message(stream, tmp, content);
    free(tmp);
    return SUCCESS;
}
