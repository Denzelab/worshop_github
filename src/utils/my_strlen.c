/*
** EPITECH PROJECT, 2025
** my_strlen
** File description:
** Task3
*/

#include "../../include/corewar.h"

int my_strlen(char const *str)
{
    int i = 0;

    while (str[i] != '\0') {
    i++;
    }
    return i;
}
