/*
** EPITECH PROJECT, 2021
** B-PSU-402-REN-4-1-ftrace-simon.racaud
** File description:
** 22/04/2021 get_registers.c
*/

#include "instruction_t.h"
#include "libc.h"

int get_registers(registers_t *dest, pid_t child_pid)
{
    if (ptrace(PTRACE_GETREGS, child_pid, 0, dest) == -1)
        return EXIT_FAILURE;
    return EXIT_SUCCESS;
}