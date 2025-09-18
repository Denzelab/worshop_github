/*
** EPITECH PROJECT, 2025
** corewar
** File description:
** corewar
*/

#include "../../include/corewar.h"

void exec_live(corewar_t *cw, process_t *proc)
{
    int param = get_param_value(cw, proc, 1);

    proc->last_live = cw->cycle;
    cw->nbr_live++;
    for (int i = 0; i < cw->champ_count; i++) {
        if (cw->champs[i].number == param) {
            cw->last_alive = i;
            mini_printf("The player %d(%s) is alive.\n",
                cw->champs[i].number, cw->champs[i].header.prog_name);
            break;
        }
    }
    proc->pc = (proc->pc + 5) % MEM_SIZE;
    proc->cycles_left = op_tab[0].nbr_cycles - 1;
}
