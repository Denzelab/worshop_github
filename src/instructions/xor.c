/*
** EPITECH PROJECT, 2025
** corewar
** File description:
** corewar
*/

#include "../../include/corewar.h"

void exec_xor(corewar_t *cw, process_t *proc)
{
    unsigned char coding_byte = cw->arena[(proc->pc + 1) % MEM_SIZE];
    int param1 = get_param_value(cw, proc, 1);
    int param2 = get_param_value(cw, proc, 2);
    int param_pos = 2 + get_param_size(coding_byte, 1) +
        get_param_size(coding_byte, 2);
    int reg_num = cw->arena[(proc->pc + param_pos) % MEM_SIZE];

    if (reg_num < 1 || reg_num > REG_NUMBER) {
        proc->pc = (proc->pc + 7) % MEM_SIZE;
        return;
    }
    proc->registers[reg_num - 1] = param1 ^ param2;
    proc->carry = (proc->registers[reg_num - 1] == 0) ? 1 : 0;
    proc->pc = (proc->pc + 7) % MEM_SIZE;
    proc->cycles_left = op_tab[7].nbr_cycles - 1;
}
