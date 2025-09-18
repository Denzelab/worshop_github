/*
** EPITECH PROJECT, 2025
** corewar
** File description:
** corewar
*/

#include "../../include/corewar.h"

void exec_zjmp(corewar_t *cw, process_t *proc)
{
    int offset = get_param_value(cw, proc, 1);

    if (proc->carry == 1) {
        proc->pc = (proc->pc + (offset % IDX_MOD)) % MEM_SIZE;
    } else {
        proc->pc = (proc->pc + 3) % MEM_SIZE;
    }
    proc->cycles_left = op_tab[8].nbr_cycles - 1;
}
