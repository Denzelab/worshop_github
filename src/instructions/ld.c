/*
** EPITECH PROJECT, 2025
** corewar
** File description:
** corewar
*/

#include "../../include/corewar.h"

void exec_ld(corewar_t *cw, process_t *proc)
{
    unsigned char coding_byte = cw->arena[(proc->pc + 1) % MEM_SIZE];
    int param1 = get_param_value(cw, proc, 1);
    int reg_num = cw->arena[(proc->pc + 2 +
        get_param_size(coding_byte, 1)) % MEM_SIZE];

    if (reg_num < 1 || reg_num > REG_NUMBER) {
        proc->pc = (proc->pc + 7) % MEM_SIZE;
        return;
    }
    proc->registers[reg_num - 1] = param1;
    proc->carry = (param1 == 0) ? 1 : 0;
    proc->pc = (proc->pc + 7) % MEM_SIZE;
    proc->cycles_left = op_tab[1].nbr_cycles - 1;
}
