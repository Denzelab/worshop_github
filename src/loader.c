/*
** EPITECH PROJECT, 2025
** corewar
** File description:
** corewar
*/

#include "../include/corewar.h"
#include "../include/op.h"

static unsigned int swap_endian(unsigned int x)
{
    return ((x >> 24) & 0x000000FF) |
           ((x >> 8)  & 0x0000FF00) |
           ((x << 8)  & 0x00FF0000) |
           ((x << 24) & 0xFF000000);
}

static int read_header(int fd, header_t *header)
{
    if (read(fd, header, sizeof(header_t)) != sizeof(header_t))
        return 84;
    header->magic = swap_endian(header->magic);
    header->prog_size = swap_endian(header->prog_size);
    if (header->magic != COREWAR_EXEC_MAGIC)
        return 84;
    return 0;
}

int read_champion(champion_t *champ)
{
    int fd = open(champ->filename, O_RDONLY);

    if (fd < 0)
        return 84;
    if (read_header(fd, &champ->header) == 84)
        return close(fd), 84;
    champ->code = malloc(champ->header.prog_size);
    if (!champ->code)
        return close(fd), 84;
    if (read(fd, champ->code, champ->header.prog_size)
        != champ->header.prog_size)
        return close(fd), 84;
    return close(fd), 0;
}
