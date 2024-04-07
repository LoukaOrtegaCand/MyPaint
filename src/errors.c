/*
** EPITECH PROJECT, 2024
** my_paint
** File description:
** handles errors
*/

#include "my_paint.h"
#include <stddef.h>

static int tab_size(char **tab)
{
    int i = 0;

    if (tab == NULL)
        return (ERR);
    for (; tab[i] != NULL; i++);
    return (i);
}

static int parse_logname(char **envp, int i, my_paint_t *all)
{
    char **array = my_str_to_word_array(envp[i]);

    if (tab_size(array) < 2)
        return (0);
    all->logname = malloc(sizeof(char) * my_strlen(array[1] + 1));
    my_strcpy(all->logname, array[1]);
    return (1);
}

int errors(int argc, char **argv, char **envp, my_paint_t *all)
{
    int dependencies = 0;

    if (argv == NULL)
        return KO;
    if (argc > 2 || (argc == 2 && my_strcmp(argv[1], "-h") != OK))
        return (KO);
    if (envp == NULL)
        return (KO);
    for (int i = 0; envp[i] != NULL; i++) {
        if (my_strncmp(envp[i], "LOGNAME=", 7) == OK) {
            dependencies += parse_logname(envp, i, all);
        }
        if (my_strncmp(envp[i], "DISPLAY=", 7) == OK)
            dependencies += 1;
        if (my_strncmp(envp[i], "XAUTHORITY=", 10) == OK)
            dependencies += 1;
    }
    if (dependencies == 3)
        return (OK);
    return (KO);
}

int help(char **argv)
{
    char str[] = "Image Creator, Editor and Saver\n\nUSAGE\n ./my_paint "
    "\n\nOPTIONS\n -h\t\tprints the usage and quit.\n\nUSER "
    "INTERACTIONS\n 'q' key\tleaves the game\n"
    "\n"
    "DESCRIPTION\n"
    "Reproduction of the well-known \"Paint\" image editor.\n"
    "It gathers numerous colors.\n";

    if (argv == NULL)
        return KO;
    if (my_strcmp(argv[1], "-h") == OK) {
        my_printf("%s", str);
        return (ERR);
    }
    return (OK);
}
