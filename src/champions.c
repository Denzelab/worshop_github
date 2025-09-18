/*
** EPITECH PROJECT, 2025
** corewar
** File description:
** corewar
*/

#include "../include/corewar.h"
#include "../include/op.h"

int load_champions(corewar_t *cw)
{
    for (int i = 0; i < cw->champ_count; i++) {
        if (read_champion(&cw->champs[i]) == 84)
            return 84;
        if (place_champion_in_arena(cw, &cw->champs[i]) == 84)
            return 84;
    }
    return 0;
}
