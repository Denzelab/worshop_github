/*
** EPITECH PROJECT, 2025
** corewar
** File description:
** corewar
*/

#include "../include/corewar.h"
#include "../include/op.h"

void execute_instruction(corewar_t *cw, process_t *proc)
{
    unsigned char opcode = cw->arena[proc->pc];
    switch (opcode) {
        case 0x01: execute_live(cw, proc); break;
        case 0x02: execute_ld(cw, proc); break;
        case 0x03: execute_st(cw, proc); break;
        case 0x04: execute_add(cw, proc); break;
        case 0x05: execute_sub(cw, proc); break;
        case 0x06: execute_and(cw, proc); break;
        case 0x07: execute_or(cw, proc); break;
        case 0x08: execute_xor(cw, proc); break;
        case 0x09: execute_zjmp(cw, proc); break;
        case 0x0a: execute_ldi(cw, proc); break;
        case 0x0b: execute_sti(cw, proc); break;
        case 0x0c: execute_fork(cw, proc); break;
        case 0x0d: execute_lld(cw, proc); break;
        case 0x0e: execute_lldi(cw, proc); break;
        case 0x0f: execute_lfork(cw, proc); break;
        case 0x10: execute_aff(cw, proc); break;
        default: proc->pc = (proc->pc + 1) % MEM_SIZE; break;
    }
}

void vm_cycle(corewar_t *cw)
{
    for (int i = 0; i < cw->process_count; i++)
        execute_instruction(cw, &cw->processes[i]);
}

int run_vm(corewar_t *cw)
{
    int cycles = 0;

    while (1) {
        cycles++;
        vm_cycle(cw);
        if (cw->dump_cycle > 0 && cycles == cw->dump_cycle) {
            dump_arena(cw->arena);
            return 0;
        }
    }
    return 0;
}
