/*
** EPITECH PROJECT, 2025
** corewar
** File description:
** corewar
*/

#include "../../include/corewar.h"

static void write_memory_value(corewar_t *cw, int address, int value)
{
    for (int i = 0; i < REG_SIZE; i++) {
        cw->arena[(address + i) % MEM_SIZE] = (value >> (24 - i * 8)) & 0xFF;
    }
}

void exec_sti(corewar_t *cw, process_t *proc)
{
    unsigned char coding_byte = cw->arena[(proc->pc + 1) % MEM_SIZE];
    int reg_num = cw->arena[(proc->pc + 2) % MEM_SIZE];
    int param2 = get_param_value(cw, proc, 2);
    int param3 = get_param_value(cw, proc, 3);
    int address = (proc->pc + ((param2 + param3) % IDX_MOD)) % MEM_SIZE;

    if (reg_num < 1 || reg_num > REG_NUMBER) {
        proc->pc = (proc->pc + 7) % MEM_SIZE;
        return;
    }
    write_memory_value(cw, address, proc->registers[reg_num - 1]);
    proc->pc = (proc->pc + 7) % MEM_SIZE;
    proc->cycles_left = op_tab[10].nbr_cycles - 1;
}
