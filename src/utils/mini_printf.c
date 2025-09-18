/*
** EPITECH PROJECT, 2025
** mini_printf.c
** File description:
** mini_printf.c
*/

#include "../../include/corewar.h"

int my_putchar(char c)
{
    write(1, &c, 1);
}

int my_putstr(const char *str)
{
    int i = 0;

    while (str[i]) {
        my_putchar(str[i]);
        i++;
    }
    return i;
}

int my_putnbr(int nb)
{
    int count = 0;

    if (nb < 0) {
        count += my_putchar('-');
        nb = -nb;
    }
    if (nb > 9)
        count += my_putnbr(nb / 10);
    count += my_putchar((nb % 10) + '0');
    return count;
}

int mini_printf1(char format, va_list args)
{
    int count = 0;

    if (format == 'd' || format == 'i')
        count += my_putnbr(va_arg(args, int));
    if (format == 's')
        count += my_putstr(va_arg(args, char *));
    if (format == 'c')
        count += my_putchar(va_arg(args, int));
    if (format == '%')
        count += my_putchar('%');
    return count;
}

int mini_printf(const char *format, ...)
{
    va_list args;
    int count = 0;
    int i = 0;

    va_start(args, format);
    while (format[i] != '\0') {
        if (format[i] == '%' && format[i + 1] != '\0') {
            i++;
            count += mini_printf1(format[i], args);
        } else {
            count += my_putchar(format[i]);
        }
        i++;
    }
    va_end(args);
    return count - 1;
}
