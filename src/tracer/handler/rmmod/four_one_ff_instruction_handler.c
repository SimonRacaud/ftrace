/*
** EPITECH PROJECT, 2021
** four_one_ff_instruction_handler.c
** File description:
** four_one_ff_instruction_handler
*/

#include "app.h"
#include "libc.h"

int four_one_ff_instruction_handler(tracer_t *tracer, registers_t *registers)
{
    printf("HERE 0x41ff\n");
    int field_byte = 0;
    long word = 0;

    word = ptrace(PTRACE_PEEKTEXT, tracer->child_pid, registers->rip);
    ptrace(PTRACE_SINGLESTEP, tracer->child_pid, NULL, NULL);
    wait4(tracer->child_pid, NULL, 0, NULL);
    ptrace(PTRACE_GETREGS, tracer->child_pid, 0, registers);
    if (word == -1)
        return EXIT_FAILURE;
    field_byte = (word & 0xff0000) >> 16;
    return execute_rmmode(tracer, registers, field_byte);
}