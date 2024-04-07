/*
** EPITECH PROJECT, 2024
** 42sh
** File description:
** my_str_to_word_array for 42sh
*/

#include <stddef.h>
#include <stdlib.h>

static int check_char(char c)
{
    if (c == ' ' || c == '\t' || c == '=' || c == '\n' || c == ':')
        return (0);
    return (1);
}

static int nbr_of_word(char *str)
{
    int i = 0;
    int nbr = 0;

    for (; !check_char(str[i]) && str[i] != '\0'; i++);
    while (str[i] != '\0') {
        for (; check_char(str[i]); i++);
        nbr += 1;
        for (; !check_char(str[i]) && str[i] != '\0'; i++);
    }
    return (nbr);
}

static int word_size(char *str, int nbr)
{
    int i = 0;
    int n = 0;
    int nbch = 0;

    for (; !check_char(str[i]) && str[i] != '\0'; i++);
    while (str[i] != '\0' && n != nbr) {
        for (; check_char(str[i]); i++);
        n += 1;
        for (; !check_char(str[i]) && str[i] != '\0'; i++);
    }
    for (; check_char(str[i]); i++)
        nbch += 1;
    return (nbch);
}

static void copytab(char **tab, char *str)
{
    int i = 0;
    int j = 0;
    int w = 0;

    for (; !check_char(str[i]) && str[i] != '\0'; i++);
    while (str[i] != '\0') {
        j = 0;
        for (; check_char(str[i]); i++) {
            tab[w][j] = str[i];
            j += 1;
        }
        tab[w][j] = '\0';
        w += 1;
        for (; !check_char(str[i]) && str[i] != '\0'; i++);
    }
}

char **my_str_to_word_array(char *str)
{
    int nbr = 0;
    int nbch = 0;
    char **tab = NULL;

    if (str == NULL)
        return (NULL);
    nbr = nbr_of_word(str);
    tab = malloc(sizeof(char *) * (nbr + 1));
    for (int i = 0; i < nbr; i++) {
        nbch = word_size(str, i);
        tab[i] = malloc(sizeof(char) * nbch + 1);
    }
    copytab(tab, str);
    tab[nbr] = NULL;
    return (tab);
}
