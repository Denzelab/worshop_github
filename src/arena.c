/*
** EPITECH PROJECT, 2025
** corewar
** File description:
** corewar
*/

#include "../include/corewar.h"
#include "../include/op.h"

int place_champion(corewar_t *cw, champion_t *champ)
{
    int start = champ->load_address;

    if (start < 0 || start >= MEM_SIZE)
        return 84;
    if (start + champ->header.prog_size > MEM_SIZE)
        return 84;
    for (int i = 0; i < champ->header.prog_size; i++) {
        if (cw->arena[start + i] != 0)
            return 84;
        cw->arena[start + i] = champ->code[i];
    }
    return 0;
}
