/*
** EPITECH PROJECT, 2025
** strdup.c
** File description:
** 1
*/

#include "../../include/corewar.h"

char *my_strdup(const char *str)
{
    int i = 0;
    int j;
    char *dup;

    if (str == NULL)
        return NULL;
    while (str[i])
        i++;
    dup = malloc(sizeof(char) * (i + 1));
    if (dup == NULL)
        return NULL;
    for (j = 0; j <= i; j++)
        dup[j] = str[j];
    return dup;
}
