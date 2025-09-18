/*
** EPITECH PROJECT, 2025
** corewar
** File description:
** init_processes
*/

#include "../include/corewar.h"

int init_processes(corewar_t *cw)
{
    cw->process_count = cw->champ_count;
    cw->processes = malloc(sizeof(process_t) * cw->process_count);
    if (!cw->processes)
        return 84;
    for (int i = 0; i < cw->champ_count; i++) {
        cw->processes[i].pc = cw->champs[i].load_address;
        for (int j = 0; j < REG_NUMBER; j++)
            cw->processes[i].registers[j] = 0;
        cw->processes[i].registers[0] = cw->champs[i].number;
        cw->processes[i].carry = 0;
        cw->processes[i].champ_index = i;
        cw->processes[i].cycles_left = 0;
        cw->processes[i].last_live = 0;
    }
    return 0;
}