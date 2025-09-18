/*
** EPITECH PROJECT, 2025
** corewar
** File description:
** corewar
*/

#include "../../include/corewar.h"

int get_param_size(unsigned char coding_byte, int param_pos)
{
    int shift = 6 - (param_pos - 1) * 2;
    int param_type = (coding_byte >> shift) & 0x03;

    switch (param_type) {
        case 0x01: return 1;
        case 0x02: return 2;
        case 0x03: return 4;
        default: return 0;
    }
}

int is_register_param(unsigned char coding_byte, int param_pos)
{
    int shift = 6 - (param_pos - 1) * 2;
    int param_type = (coding_byte >> shift) & 0x03;

    return param_type == 0x01;
}

static int read_param_from_arena(corewar_t *cw, int pos, int size)
{
    int result = 0;

    for (int i = 0; i < size; i++) {
        result = (result << 8) | cw->arena[(pos + i) % MEM_SIZE];
    }
    if (size == 2 && (result & 0x8000))
        result |= 0xFFFF0000;
    return result;
}

int get_param_value(corewar_t *cw, process_t *proc, int param_pos)
{
    unsigned char coding_byte = cw->arena[(proc->pc + 1) % MEM_SIZE];
    int param_offset = 2;
    int param_type;
    int shift;

    for (int i = 1; i < param_pos; i++)
        param_offset += get_param_size(coding_byte, i);
    shift = 6 - (param_pos - 1) * 2;
    param_type = (coding_byte >> shift) & 0x03;
    switch (param_type) {
        case 0x01: {
            int reg_num = cw->arena[(proc->pc + param_offset) % MEM_SIZE];
            if (reg_num < 1 || reg_num > REG_NUMBER)
                return 0;
            return proc->registers[reg_num - 1];
        }
        case 0x02:
            return read_param_from_arena(cw, proc->pc + param_offset, 2);
        case 0x03:
            return read_param_from_arena(cw, proc->pc + param_offset, 4);
        default:
            return 0;
    }
}
