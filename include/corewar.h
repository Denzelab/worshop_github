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

typedef struct champion_s {
    int number;
    char *filename;
    int load_address;
    header_t header;
    unsigned char *code;
} champion_t;

typedef struct corewar_s {
    champion_t champs[MAX_CHAMPS];
    int champ_count;
    unsigned char arena[MEM_SIZE];
    int dump_cycle;
    struct process_s *processes;
    int process_count;
} corewar_t;

typedef struct process_s {
    int pc;
    int registers[REG_NUMBER];
    int carry;
    int champ_index;
} process_t;

int init_processes(corewar_t *cw);
int corewar_run(corewar_t *cw);
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
