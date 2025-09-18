/*
** EPITECH PROJECT, 2025
** corewar
** File description:
** corewar
*/

#include "../include/corewar.h"
#include "../include/op.h"

int main(int argc, char **argv)
{
    corewar_t cw = {0};

    if (argc < 2)
        return usage(), 84;
    if (argc == 2 && my_strcmp(argv[1], "-h") == 0)
        return usage(), 0;
    if (parse_args(argc, argv, &cw) == 84)
        return 84;
    if (cw.champ_count == 0)
        return 84;
    init_arena(&cw);
    if (load_champions(&cw) == 84)
        return 84;
    if (init_processes(&cw) == 84)
        return 84;
    return run_vm(&cw);
}
