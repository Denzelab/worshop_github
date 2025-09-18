/*
** EPITECH PROJECT, 2025
** corewar
** File description:
** corewar
*/

#include "../../include/corewar.h"

void usage(void)
{
    my_putstr("USAGE\n");
    my_putstr("./corewar [-dump nbr_cycle] [[-n prog_number]");
    my_putstr(" [-a load_address] prog_name] ...\n");
    my_putstr("DESCRIPTION\n");
    my_putstr("-dump nbr_cycle dumps the memory after the nbr_cycle ");
    my_putstr("(execution if the round isn't\n");
    my_putstr("already over) with the following format: 32 bytes/line in ");
    my_putstr("hexadecimal (A0BCDEFE1DD3...)\n");
    my_putstr("-n prog_number sets the next program's number. By default, ");
    my_putstr("the first free number in the\n");
    my_putstr("parameter order\n");
    my_putstr("-a load_address sets the next program's loading address. ");
    my_putstr("When no address is specified,\n");
    my_putstr("optimize the addresses so that the processes are as far ");
    my_putstr("away from each other as\n");
    my_putstr("possible. The addresses are MEM_SIZE modulo.\n");
}
