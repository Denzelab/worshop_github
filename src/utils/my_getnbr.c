/*
** EPITECH PROJECT, 2025
** my_getnbr
** File description:
** 1
*/

#include "../../include/corewar.h"

int my_getnbr(char const *c)
{
    int i = 0;
    int j = 0;
    int a = 1;
    int res = 0;
    int r;

    while (c[i] != '\0') {
        if (c[i] == '-')
            a = -a;
        i++;
    }
    while (c[j] != '\0') {
        if (c[j] >= 48 && c[j] <= 57)
            r = c[j] - 48;
        res = res * 10 + r;
        j++;
    }
    res = a * res;
    return res;
}
