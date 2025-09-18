/*
** EPITECH PROJECT, 2025
** corewar
** File description:
** corewar
*/

#include "../include/corewar.h"
#include "../include/op.h"

static void execute_instruction(corewar_t *cw, process_t *proc)
{
    unsigned char opcode = cw->arena[proc->pc];

    if (proc->cycles_left > 0) {
        proc->cycles_left--;
        return;
    }
    switch (opcode) {
        case 0x01: exec_live(cw, proc); break;
        case 0x02: exec_ld(cw, proc); break;
        case 0x03: exec_st(cw, proc); break;
        case 0x04: exec_add(cw, proc); break;
        case 0x05: exec_sub(cw, proc); break;
        case 0x06: exec_and(cw, proc); break;
        case 0x07: exec_or(cw, proc); break;
        case 0x08: exec_xor(cw, proc); break;
        case 0x09: exec_zjmp(cw, proc); break;
        case 0x0a: exec_ldi(cw, proc); break;
        case 0x0b: exec_sti(cw, proc); break;
        case 0x0c: exec_fork(cw, proc); break;
        case 0x0d: exec_lld(cw, proc); break;
        case 0x0e: exec_lldi(cw, proc); break;
        case 0x0f: exec_lfork(cw, proc); break;
        case 0x10: exec_aff(cw, proc); break;
        default: proc->pc = (proc->pc + 1) % MEM_SIZE; break;
    }
}

static void vm_cycle(corewar_t *cw)
{
    for (int i = 0; i < cw->process_count; i++)
        execute_instruction(cw, &cw->processes[i]);
}

static int check_alive_processes(corewar_t *cw)
{
    int alive = 0;

    for (int i = 0; i < cw->process_count; i++) {
        if (cw->cycle - cw->processes[i].last_live < cw->cycle_to_die)
            alive++;
    }
    return alive;
}

static void remove_dead_processes(corewar_t *cw)
{
    int new_count = 0;

    for (int i = 0; i < cw->process_count; i++) {
        if (cw->cycle - cw->processes[i].last_live < cw->cycle_to_die) {
            cw->processes[new_count] = cw->processes[i];
            new_count++;
        }
    }
    cw->process_count = new_count;
}

int run_vm(corewar_t *cw)
{
    cw->cycle_to_die = CYCLE_TO_DIE;
    cw->cycle = 0;

    while (cw->process_count > 0) {
        cw->cycle++;
        vm_cycle(cw);
        if (cw->dump_cycle > 0 && cw->cycle == cw->dump_cycle) {
            dump_arena(cw->arena);
            return 0;
        }
        if (cw->cycle % cw->cycle_to_die == 0) {
            if (cw->nbr_live >= NBR_LIVE) {
                cw->cycle_to_die -= CYCLE_DELTA;
                cw->nbr_live = 0;
            }
            remove_dead_processes(cw);
        }
    }
    mini_printf("The player %d(%s) has won.\n",
        cw->champs[cw->last_alive].number,
        cw->champs[cw->last_alive].header.prog_name);
    return 0;
}