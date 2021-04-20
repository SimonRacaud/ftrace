/*
** EPITECH PROJECT, 2021
** correct_unknow_name.c
** File description:
** correct_unknow_name
*/

#include "ftrace.h"

char *get_correct_name(char *name, unsigned long long rip, data_link_t *tab)
{
    char *tmp = NULL;
    size_t u = 0;

    if (name)
        return name;
    for (u = 0; tab[u].name; u++) {
        if (rip >= tab[u].start && rip <= tab[u].end) {
            break;
        }
    }
    if (!tab[u].name)
        return NULL;
    asprintf(&tmp, "func_0x%llX@%s", rip, tab[u].name);
    return tmp;
}