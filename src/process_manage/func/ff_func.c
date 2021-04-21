/*
** EPITECH PROJECT, 2021
** ff_func.c
** File description:
** ff_func
*/

#include "ftrace.h"

bool ff_func(ftrace_t *data,
__attribute__((unused)) struct user_regs_struct *regs)
{
    return push_back(&data->leaving_list, strdup("C_OK"));
}