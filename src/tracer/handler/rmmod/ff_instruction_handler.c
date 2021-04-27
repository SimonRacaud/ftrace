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
    if (step_forward(tracer->child_pid, NULL) == EXIT_FAILURE)
        return EXIT_FAILURE;
    if (get_registers(registers, tracer->child_pid) == EXIT_FAILURE)
        return EXIT_FAILURE;
    if (word == -1)
        return EXIT_FAILURE;
    field_byte = (word & 0xff00) >> 8;
    return execute_rmmode(tracer, registers, field_byte);
}