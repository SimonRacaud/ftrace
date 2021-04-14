/*
** EPITECH PROJECT, 2021
** display_help.c
** File description:
** display_help
*/

#include "ftrace.h"

void display_help(const char *binary)
{
    fprintf(stdout, "USAGE: %s <command>\n", binary);
}