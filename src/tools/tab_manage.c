/*
** EPITECH PROJECT, 2021
** tab_manage.c
** File description:
** tab_manage
*/

#include "ftrace.h"

static size_t get_tab_size(const char **tab)
{
    size_t i = 0;

    for (i = 0; tab && tab[i]; i++);
    return i;
}

bool push_back(char ***tab, char *name)
{
    size_t size = get_tab_size((const char **) *tab);

    *tab = realloc(*tab, sizeof(char *) * (size + 2));
    if (!(*tab))
        return false;
    (*tab)[size] = name;
    (*tab)[size + 1] = NULL;
    return true;
}

char *pop_back(char **tab)
{
    char *tmp = NULL;
    size_t size = get_tab_size((const char **) tab);

    if (size == 0)
        return NULL;
    tmp = tab[size - 1];
    tab[size - 1] = NULL;
    return tmp;
}