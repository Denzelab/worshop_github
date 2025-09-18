/*
** EPITECH PROJECT, 2025
** corewar
** File description:
** corewar
*/

#include "../include/corewar.h"
#include "../include/op.h"

static void print_line(unsigned char *arena, int start)
{
    mini_printf("%04x :", start);
    for (int i = 0; i < 32; i++)
        mini_printf(" %02x", arena[start + i]);
    mini_printf("\n");
}

void dump_arena(unsigned char *arena)
{
    for (int i = 0; i < MEM_SIZE; i += 32)
        print_line(arena, i);
}
