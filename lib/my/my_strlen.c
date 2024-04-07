/*
** EPITECH PROJECT, 2023
** my_strlen
** File description:
** Function that counts and returns the number of caracters of a string
*/

#include <stddef.h>

int my_strlen(char const *str)
{
    int i = 0;

    if (str == NULL)
    return (0);
    for (; str[i] != '\0' && str[i] != '\n'; i++);
    return (i);
}
