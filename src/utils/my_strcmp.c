/*
** EPITECH PROJECT, 2025
** my_strcmp
** File description:
** 1
*/

#include "../../include/corewar.h"

int my_strcmp(const char *s1, const char *s2)
{
    int i = 0;
    int a = my_strlen(s1);
    int b = my_strlen(s2);

    if (a != b)
        return -1;
    while (s1[i] != '\0') {
        if (s1[i] != s2[i])
            return -1;
        i++;
    }
    return 0;
}
