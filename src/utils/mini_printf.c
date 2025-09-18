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

static int put_hex(unsigned int nb, int width)
{
    char hex_digits[] = "0123456789abcdef";
    char buffer[16];
    int i = 0;
    int count = 0;
    
    if (nb == 0) {
        buffer[i++] = '0';
    } else {
        while (nb > 0) {
            buffer[i++] = hex_digits[nb % 16];
            nb /= 16;
        }
    }
    while (i < width) {
        my_putchar('0');
        count++;
    }
    for (int j = i - 1; j >= 0; j--) {
        my_putchar(buffer[j]);
        count++;
    }
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
            if (format[i] == 'd' || format[i] == 'i') {
                count += my_putnbr(va_arg(args, int));
            } else if (format[i] == 's') {
                count += my_putstr(va_arg(args, char *));
            } else if (format[i] == 'c') {
                count += my_putchar(va_arg(args, int));
            } else if (format[i] == '0' && format[i + 1] == '2' && format[i + 2] == 'x') {
                count += put_hex(va_arg(args, unsigned int) & 0xFF, 2);
                i += 2;
            } else if (format[i] == '0' && format[i + 1] == '4' && format[i + 2] == 'x') {
                count += put_hex(va_arg(args, unsigned int) & 0xFFFF, 4);
                i += 2;
            } else if (format[i] == '%') {
                count += my_putchar('%');
            }
        } else {
            count += my_putchar(format[i]);
        }
        i++;
    }
    va_end(args);
    return count;
}