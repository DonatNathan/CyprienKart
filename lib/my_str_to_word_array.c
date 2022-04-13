/*
** EPITECH PROJECT, 2022
** my_str_to_word_array
** File description:
** my_str_to_word_array
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "my.h"

int check_parsers(char c, char *parser)
{
    int i = 0;

    if (!parser)
        return (1);
    for (;parser[i] != '\0'; i++)
        if (c == parser[i])
            return (0);
    return (1);
}

static char *get_av(char *str, int *ptr, char *parsers)
{
    char *save;
    int i = 0;

    while (check_parsers(str[*ptr], parsers) == 0)
        *ptr += 1;
    while (check_parsers(str[*ptr + i], parsers) == 1
    && str[*ptr + i] != '\0')
        i += 1;
    if ((save = malloc(i + 1)) == NULL)
        return NULL;
    save[i] = '\0';
    i = 0;
    while (check_parsers(str[*ptr], parsers) == 1 && str[*ptr] != '\0') {
        save[i] = str[*ptr];
        i += 1;
        *ptr += 1;
    }
    return save;
}

int get_ac(char *str, char *parsers)
{
    int i = 0;
    int y = 0;

    for (;check_parsers(str[y], parsers) == 0 && str[y] != '\0'; y++);
    for (;str[y] != '\0'; y++) {
        if (check_parsers(str[y], parsers) == 1 && str[y] != '\0' &&
        (check_parsers(str[y + 1], parsers) == 0 || str[y + 1] == '\0'))
            i += 1;
    }
    return i;
}

char **my_str_to_word_array(char *str, char *parsers)
{
    char **av;
    int ac = get_ac(str, parsers);
    int ptr = 0;
    int n = 0;

    if (!parsers) {
        av = &str;
        return av;
    }
    if ((av = malloc(sizeof(char *) * (ac + 1))) == NULL)
        return (NULL);
    for (;n < ac; n++)
        av[n] = get_av(str, &ptr, parsers);
    av[n] = NULL;
    return av;
}
