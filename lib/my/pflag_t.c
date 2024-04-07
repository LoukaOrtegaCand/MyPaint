/*
** EPITECH PROJECT, 2023
** funct_c
** File description:
** function for flag 't'
*/

#include "my.h"
#include <stdarg.h>
#include <stddef.h>

int pfunct_t(int count, va_list list)
{
    char **tab = va_arg(list, char **);

    for (int y = 0; tab[y] != NULL; y++) {
        count += pmy_putstr(tab[y]);
        count += pmy_putchar('\n');
    }
    return (count);
}
