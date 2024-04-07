/*
** EPITECH PROJECT, 2024
** my_strendcmp.c
** File description:
** cmp the n lasts char in a string
*/

#include "my.h"
#include <stdio.h>

int my_strendcmp(char *s1, char *s2)
{
    size_t i = 0;
    size_t j = 0;

    for (; s1[i] != '\0'; i++);
    for (; s2[j] != '\0'; j++);
    while (s1[i] == s2[j] && i > 0 && j > 0) {
        i -= 1;
        j -= 1;
    }
    return (s1[i] - s2[j]);
}
