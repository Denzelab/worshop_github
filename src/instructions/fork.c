/*
** EPITECH PROJECT, 2025
** corewar
** File description:
** corewar
*/

#include "../../include/corewar.h"

static int add_new_process(corewar_t *cw, process_t *parent, int new_pc)
{
    process_t *new_processes = realloc(cw->processes,
        sizeof(process_t) * (cw->process_count + 1));

    if (!new_processes)
        return 84;
    cw->processes = new_processes;
    cw->processes[cw->process_count] = *parent;
    cw->processes[cw->process_count].pc = new_pc;
    cw->processes[cw->process_count].cycles_left = 0;
    cw->process_count++;
    return 0;
}

void exec_fork(corewar_t *cw, process_t *proc)
{
    int offset = get_param_value(cw, proc, 1);
    int new_pc = (proc->pc + (offset % IDX_MOD)) % MEM_SIZE;

    add_new_process(cw, proc, new_pc);
    proc->pc = (proc->pc + 3) % MEM_SIZE;
    proc->cycles_left = op_tab[11].nbr_cycles - 1;
}
