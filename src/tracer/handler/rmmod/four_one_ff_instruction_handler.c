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
    printf("here 2\n");
    int field_byte = 0;
    long word = 0;

    word = ptrace(PTRACE_PEEKTEXT, tracer->child_pid, registers->rip);
    if (step_forward(tracer->child_pid, NULL) == EXIT_FAILURE)
        return EXIT_FAILURE;
    if (get_registers(registers, tracer->child_pid) == EXIT_FAILURE)
        return EXIT_FAILURE;
    if (word == -1)
        return EXIT_FAILURE;
    field_byte = (word & 0xff0000) >> 16;
    return execute_rmmode(tracer, registers, field_byte);
}