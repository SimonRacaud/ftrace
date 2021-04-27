/*
** EPITECH PROJECT, 2021
** e_eight_instruction_handler.c
** File description:
** e_eight_instruction_handler
*/

#include "app.h"
#include "libc.h"

extern const char ENTERING_FUNCTION[];

int e_eight_instruction_handler(tracer_t *tracer, registers_t *registers)
{
    char *name = NULL;
    int ret = 0;

    if (step_forward(tracer->child_pid, &ret) == EXIT_FAILURE)
        return EXIT_FAILURE;
    if (get_registers(registers, tracer->child_pid) == EXIT_FAILURE)
        return EXIT_FAILURE;
    if (ptrace(PTRACE_PEEKDATA, tracer->child_pid, registers->rip, NULL) == -1)
        return false;
    name = browse_function_name(tracer->child_pid, registers->rip);
    if (!name)
        return EXIT_FAILURE;
    fprintf(stderr, ENTERING_FUNCTION, name, registers->rip);
    return stack_push(&tracer->call_names, name);
}