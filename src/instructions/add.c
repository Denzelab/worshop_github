/*
** EPITECH PROJECT, 2025
** corewar
** File description:
** corewar
*/

#include "../../include/corewar.h"

void exec_add(corewar_t *cw, process_t *proc)
{
    int reg1 = cw->arena[(proc->pc + 2) % MEM_SIZE];
    int reg2 = cw->arena[(proc->pc + 3) % MEM_SIZE];
    int reg3 = cw->arena[(proc->pc + 4) % MEM_SIZE];

    if (reg1 < 1 || reg1 > REG_NUMBER ||
        reg2 < 1 || reg2 > REG_NUMBER ||
        reg3 < 1 || reg3 > REG_NUMBER) {
        proc->pc = (proc->pc + 5) % MEM_SIZE;
        return;
    }
    proc->registers[reg3 - 1] = proc->registers[reg1 - 1] + 
        proc->registers[reg2 - 1];
    proc->carry = (proc->registers[reg3 - 1] == 0) ? 1 : 0;
    proc->pc = (proc->pc + 5) % MEM_SIZE;
    proc->cycles_left = op_tab[3].nbr_cycles - 1;
}
