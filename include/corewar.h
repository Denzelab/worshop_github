/*
** EPITECH PROJECT, 2025
** corewar
** File description:
** corewar
*/

#ifndef COREWAR_H_
    #define COREWAR_H_
    #include <stdlib.h>
    #include <stdio.h>
    #include <unistd.h>
    #include <string.h>
    #include <fcntl.h>
    #include <stddef.h>
    #include <ctype.h>
    #include <stdarg.h>
    #include "op.h"

    #define MAX_CHAMPS 4

typedef struct {
    char *filename;
    header_t header;
    unsigned char *code;
    int number;
    int load_address;
} champion_t;

typedef struct {
    int pc;
    int registers[REG_NUMBER];
    int carry;
    int champ_index;
    int cycles_left;
    int last_live;
} process_t;

typedef struct {
    unsigned char arena[MEM_SIZE];
    champion_t champs[MAX_CHAMPS];
    process_t *processes;
    int champ_count;
    int process_count;
    int dump_cycle;
    int cycle;
    int cycle_to_die;
    int nbr_live;
    int last_alive;
} corewar_t;

void exec_live(corewar_t *cw, process_t *proc);
void exec_ld(corewar_t *cw, process_t *proc);
void exec_st(corewar_t *cw, process_t *proc);
void exec_add(corewar_t *cw, process_t *proc);
void exec_sub(corewar_t *cw, process_t *proc);
void exec_and(corewar_t *cw, process_t *proc);
void exec_or(corewar_t *cw, process_t *proc);
void exec_xor(corewar_t *cw, process_t *proc);
void exec_zjmp(corewar_t *cw, process_t *proc);
void exec_ldi(corewar_t *cw, process_t *proc);
void exec_sti(corewar_t *cw, process_t *proc);
void exec_fork(corewar_t *cw, process_t *proc);
void exec_lld(corewar_t *cw, process_t *proc);
void exec_lldi(corewar_t *cw, process_t *proc);
void exec_lfork(corewar_t *cw, process_t *proc);
void exec_aff(corewar_t *cw, process_t *proc);
int place_champion_in_arena(corewar_t *cw, champion_t *champ);
void assign_numbers_and_addresses(corewar_t *cw);
int get_param_value(corewar_t *cw, process_t *proc, int param_pos);
int is_register_param(unsigned char coding_byte, int param_pos);
int get_param_size(unsigned char coding_byte, int param_pos);
int init_processes(corewar_t *cw);
int parse_args(int ac, char **av, corewar_t *cw);
int set_dump_cycle(corewar_t *cw, char **av, int *i, int ac);
int parse_champion_opts(corewar_t *cw, char **av, int *i, int ac);
int add_champion(corewar_t *cw, char *filename);
void init_arena(corewar_t *cw);
int place_champion(corewar_t *cw, champion_t *champ);
int add_champion_with_opts(corewar_t *cw,
    char *filename, int number, int address);
int my_strcmp(const char *s1, const char *s2);
int my_strlen(const char *str);
int valid_number(const char *str);
int my_getnbr(const char *str);
char *my_strdup(const char *src);
int my_putstr(const char *str);
int my_putchar(char c);
int my_putnbr(int nb);
int mini_printf(const char *format, ...);
int read_champion(champion_t *champ);
int place_champion(corewar_t *cw, champion_t *champ);
int load_champions(corewar_t *cw);
int run_vm(corewar_t *cw);
void dump_arena(unsigned char *arena);
void usage(void);

#endif
