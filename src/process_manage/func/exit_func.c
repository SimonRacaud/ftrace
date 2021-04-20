/*
** EPITECH PROJECT, 2021
** exit_func.c
** File description:
** exit_func
*/

#include "ftrace.h"

bool exit_func(ftrace_t *data, struct user_regs_struct *regs, long rip)
{
    char *name = pop_back(data->leaving_list);

    fprintf(stderr, "Leaving function %s\n", (name) ? name : "WUTTTTTT.SG");
    free(name);
    return true;
}