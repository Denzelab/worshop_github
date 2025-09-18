/*
** EPITECH PROJECT, 2025
** corewar
** File description:
** corewar
*/

#include "../../include/corewar.h"

static int read_memory_direct(corewar_t *cw, int address)
{
    int result = 0;

    for (int i = 0; i < IND_SIZE; i++) {
        result = (result << 8) | cw->arena[(address + i) % MEM_SIZE];
    }
    return result;
}

void exec_lldi(corewar_t *cw, process_t *proc)
{
    unsigned char coding_byte = cw->arena[(proc->pc + 1) % MEM_SIZE];
    int param1 = get_param_value(cw, proc, 1);
    int param2 = get_param_value(cw, proc, 2);
    int param_pos = 2 + get_param_size(coding_byte, 1) +
        get_param_size(coding_byte, 2);
    int reg_num = cw->arena[(proc->pc + param_pos) % MEM_SIZE];
    int address = (proc->pc + param1 + param2) % MEM_SIZE;

    if (reg_num < 1 || reg_num > REG_NUMBER) {
        proc->pc = (proc->pc + 7) % MEM_SIZE;
        return;
    }
    proc->registers[reg_num - 1] = read_memory_direct(cw, address);
    proc->carry = (proc->registers[reg_num - 1] == 0) ? 1 : 0;
    proc->pc = (proc->pc + 7) % MEM_SIZE;
    proc->cycles_left = op_tab[13].nbr_cycles - 1;
}
