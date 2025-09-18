/*
** EPITECH PROJECT, 2025
** corewar
** File description:
** corewar
*/

#include "../../include/corewar.h"
#include "../../include/op.h"

static int parse_dump(int *i, int argc, char **argv, corewar_t *cw)
{
    if (*i + 1 >= argc)
        return write(2, "Missing value after -dump\n", 26), 84;
    cw->dump_cycle = my_getnbr(argv[*i + 1]);
    if (cw->dump_cycle <= 0)
        return write(2, "Invalid dump cycle\n", 19), 84;
    *i += 2;
    return 0;
}

int add_champion_with_opts(corewar_t *cw,
    char *filename, int number, int address)
{
    if (cw->champ_count >= MAX_CHAMPS)
        return 84;
    cw->champs[cw->champ_count].filename = my_strdup(filename);
    cw->champs[cw->champ_count].number = number;
    cw->champs[cw->champ_count].load_address = address;
    cw->champ_count++;
    return 0;
}

int add_champion(corewar_t *cw, char *filename)
{
    return add_champion_with_opts(cw, filename, 0, -1);
}

int parse_champion_opts(corewar_t *cw, char **av, int *i, int ac)
{
    int number = 0;
    int address = -1;

    while (*i < ac && (my_strcmp(av[*i], "-n") == 0
        || my_strcmp(av[*i], "-a") == 0)) {
        if (my_strcmp(av[*i], "-n") == 0) {
            if (*i + 1 >= ac || !valid_number(av[*i + 1]))
                return 84;
            number = my_getnbr(av[(*i)]);
            (*i)++;
        } else if (my_strcmp(av[*i], "-dump") == 0) {
            if (parse_dump(i, ac, av, cw) == 84)
                return 84;
            continue;
        } else if (my_strcmp(av[*i], "-a") == 0) {
            if (*i + 1 >= ac || !valid_number(av[*i + 1]))
                return 84;
            address = my_getnbr(av[(*i)]);
            (*i)++;
        }
        (*i)++;
    }
    if (*i >= ac)
        return 84;
    return add_champion_with_opts(cw, av[*i], number, address);
}

int set_dump_cycle(corewar_t *cw, char **av, int *i, int ac)
{
    if (*i + 1 >= ac || !valid_number(av[*i + 1]))
        return 84;
    cw->dump_cycle = my_getnbr(av[*i + 1]);
    (*i)++;
    return 0;
}

int parse_args(int ac, char **av, corewar_t *cw)
{
    for (int i = 1; i < ac; i++) {
        if (my_strcmp(av[i], "-h") == 0)
            return usage(), 84;
        if (my_strcmp(av[i], "-dump") == 0) {
            if (set_dump_cycle(cw, av, &i, ac) == 84)
                return 84;
            continue;
        }
        if (my_strcmp(av[i], "-n") == 0 || my_strcmp(av[i], "-a") == 0) {
            if (parse_champion_opts(cw, av, &i, ac) == 84)
                return 84;
            continue;
        }
        if (add_champion(cw, av[i]) == 84)
            return 84;
    }
    return 0;
}
