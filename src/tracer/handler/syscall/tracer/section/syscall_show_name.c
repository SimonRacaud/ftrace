/*
** EPITECH PROJECT, 2021
** B-PSU-402-REN-4-1-ftrace-simon.racaud
** File description:
** 23/04/2021 syscall_show_name.c
*/

#include "syscall.h"

void print_syscall_name(const syscall_t *info, uint *line_length)
{
    *line_length += fprintf(stderr, "Syscall %s(", info->name);
}