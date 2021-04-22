/*
** EPITECH PROJECT, 2021
** B-PSU-402-REN-4-1-ftrace-simon.racaud
** File description:
** 22/04/2021 usage.c
*/

#include "app.h"

bool show_usages(int argc, char **argv)
{
    for (size_t i = 0; i < (size_t)argc; i++) {
        if (!strcmp(argv[i], "-h") || !strcmp(argv[i], "--help")) {
            return true;
        }
    }
    return false;
}

int usage(int status, const char *bin)
{
    printf("Usage: %s [filepath]\n", bin);
    return status;
}