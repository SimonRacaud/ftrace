/*
** EPITECH PROJECT, 2021
** ff_instruction_handler.c
** File description:
** ff_instruction_handler
*/

#include "app.h"
#include "libc.h"

int ff_instruction_handler(tracer_t *tracer, registers_t *registers)
{
    int field_byte = 0;
    long word = 0;

    word = ptrace(PTRACE_PEEKTEXT, tracer->child_pid, registers->rip);
    ptrace(PTRACE_SINGLESTEP, tracer->child_pid, NULL, NULL);
    wait4(tracer->child_pid, NULL, 0, NULL);
    ptrace(PTRACE_GETREGS, tracer->child_pid, 0, registers);
    if (word == -1)
        return EXIT_FAILURE;
    field_byte = (word & 0xff00) >> 8;
    return execute_rmmode(tracer, registers, field_byte);
}