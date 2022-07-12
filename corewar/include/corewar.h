/*
** EPITECH PROJECT, 2022
** corewar
** File description:
** corewar
*/

#ifndef COREWAR_H
    #define COREWAR_H
    #include <unistd.h>
    #include "../../include/op.h"
    #include <sys/stat.h>
    #include <fcntl.h>
    #include <stdio.h>
    #include <stdlib.h>
    #include <string.h>
    #define SUCCESS 0
    #define FAILURE 1
    #define FALSE 0
    #define TRUE 1
    #define BLACK_BG    "\e[40m\e[30m%02X\e[0m "
    #define BLUE_BG     "\e[44m\e[34m%02X\e[0m "
    #define RED_BG      "\e[41m\e[31m%02X\e[0m "
    #define GREEN_BG    "\e[42m\e[32m%02X\e[0m "
    #define YELLOW_BG   "\e[43m\e[33m%02X\e[0m "
    #define LEFT(nbr) (((nbr>>24) & 0xff) | ((nbr<<8) & 0xff0000))
    #define RIGHT(nbr) (((nbr>>8) & 0xff00) | ((nbr<<24) & 0xff000000))
    #define SWAP_ENDIAN(nbr) (LEFT(nbr) | RIGHT(nbr))
    #define SWAP_ENDIAN_16(nbr) (((nbr>>24) & 0xff) | ((nbr<<8) & 0xff00))
    #define REGISTER(c) ((c & 0xC0) == 0x40 ? 1 : 0)
    #define INDIRECT(c) ((c & 0xC0) == 0xC0 ? 1 : 0)
    #define DIRECT(c) ((c & 0xC0) == 0x80 ? 1 : 0)

    #define ERROR_MSG "ahhhh no, don't agree!\n"

struct champion_s
{
    int number;
    int load_adress;
    header_t header;
    int registers[REG_NUMBER + 1];
    int pc;
    int carry;
    int is_alive;
    int living;
    int is_waiting;
    int wait;
    unsigned char *code;
};

typedef struct champion_s champion_t;

struct arena_s
{
    unsigned char *battlefield;
    int *user_id;
    int cycle_to_die;
    int cycle;
};

typedef struct arena_s arena_t;

struct info_s
{
    int dump;
    int nb_champions;
    int nb_live;
    int last_user_live;
    champion_t *champions;
    arena_t arena;
};

typedef struct info_s info_t;

void win(info_t *info);
int my_verify_nbr(char *str);
int check_all_char(char *str, char *to_check);
int char_in_str(char c, char *str);
int check_cor(char *str);
int my_strlen(char *str);
int my_put_nbr(int nb);
int my_atoi(char const *str);
int count_arg(char **array);
char **my_str_to_word_array(char *str, char *c);
int my_strcmp(char *s1, char *s2);
int zjump(info_t *info, champion_t *champ);
int xor(info_t *info, champion_t *champ);
int sub(info_t *info, champion_t *champ);
int sti(info_t *info, champion_t *champ);
int st(info_t *info, champion_t *champ);
int or(info_t *info, champion_t *champ);
int lldi(info_t *info, champion_t *champ);
int lld(info_t *info, champion_t *champ);
int lfork(info_t *info, champion_t *champ);
int live(info_t *info, champion_t *champ);
int ldi(info_t *info, champion_t *champ);
int ld(info_t *info, champion_t *champ);
int fork_f(info_t *info, champion_t *champ);
int and(info_t *info, champion_t *champ);
int aff(info_t *info, champion_t *champ);
int add(info_t *info, champion_t *champ);
int check_alive(info_t *info);
void refresh_alive(info_t *info);
void print_arena(info_t *info);
int set_arena(info_t *info);
int init_arena(info_t *info);
void print_hexarena(info_t *info);
void *my_printf(char const *format, ...);
void loop(info_t *info);
int get_type(char code, champion_t *champ, info_t *info);
int get_index(info_t *info, champion_t *champ);
champion_t copy_champ(champion_t *champ);

#endif