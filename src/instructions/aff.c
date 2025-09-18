/*
** EPITECH PROJECT, 2025
** corewar
** File description:
** corewar
*/

#include "../../include/corewar.h"

void exec_aff(corewar_t *cw, process_t *proc)
{
    int reg_num = cw->arena[(proc->pc + 2) % MEM_SIZE];

    if (reg_num < 1 || reg_num > REG_NUMBER) {
        proc->pc = (proc->pc + 3) % MEM_SIZE;
        return;
    }
    printf("%c", proc->registers[reg_num - 1] % 256);
    proc->pc = (proc->pc + 3) % MEM_SIZE;
    proc->cycles_left = op_tab[15].nbr_cycles - 1;
}
