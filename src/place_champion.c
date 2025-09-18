/*
** EPITECH PROJECT, 2025
** corewar
** File description:
** corewar
*/

#include "../include/corewar.h"

int place_champion(corewar_t *cw, champion_t *champ)
{
    int start = champ->load_address;
    
    if (start < 0 || start + champ->header.prog_size > MEM_SIZE)
        return 84;
    for (int i = 0; i < champ->header.prog_size; i++)
        cw->arena[(start + i) % MEM_SIZE] = champ->code[i];
    return 0;
}
