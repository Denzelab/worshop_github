/*
** EPITECH PROJECT, 2025
** corewar
** File description:
** corewar
*/

#include "../../include/corewar.h"

static void store_to_memory(corewar_t *cw, int address, int value)
{
    for (int i = 0; i < REG_SIZE; i++) {
        cw->arena[(address + i) % MEM_SIZE] = (value >> (24 - i * 8)) & 0xFF;
    }
}

void exec_st(corewar_t *cw, process_t *proc)
{
    unsigned char coding_byte = cw->arena[(proc->pc + 1) % MEM_SIZE];
    int reg_num = cw->arena[(proc->pc + 2) % MEM_SIZE];
    int param_pos = 2 + get_param_size(coding_byte, 1);

    if (reg_num < 1 || reg_num > REG_NUMBER) {
        proc->pc = (proc->pc + 7) % MEM_SIZE;
        return;
    }
    if (is_register_param(coding_byte, 2)) {
        int dest_reg = cw->arena[(proc->pc + param_pos) % MEM_SIZE];
        if (dest_reg >= 1 && dest_reg <= REG_NUMBER)
            proc->registers[dest_reg - 1] = proc->registers[reg_num - 1];
    } else {
        int offset = get_param_value(cw, proc, 2);
        int address = (proc->pc + (offset % IDX_MOD)) % MEM_SIZE;
        store_to_memory(cw, address, proc->registers[reg_num - 1]);
    }
    proc->pc = (proc->pc + 7) % MEM_SIZE;
    proc->cycles_left = op_tab[2].nbr_cycles - 1;
}
