/*
** EPITECH PROJECT, 2025
** valid_number
** File description:
** 1
*/

#include "../../include/corewar.h"

int cut_valid_number(const char *str, int *i, int *j)
{
    if (str[*i] == '.') {
            *j = *j + 1;
            if (*j > 1)
                return 84;
        } else if (!isdigit(str[*i]))
        return 84;
}

int valid_number(const char *\
    str)
{
    int i = 0;
    int j = 0;
    int k = 5;

    if (str[i] == '-' || str[i] == '+')
        i++;
    while (str[i] && str[i] != '\n') {
        k = cut_valid_number(str, &i, &j);
        if (k == 84)
            return 0;
        i++;
    }
    return 1;
}
