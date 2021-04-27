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

    ptrace(PTRACE_SINGLESTEP, tracer->child_pid, NULL, NULL);
    wait4(tracer->child_pid, &ret, 0, NULL);
    ptrace(PTRACE_GETREGS, tracer->child_pid, 0, registers->rip);
    if (ptrace(PTRACE_PEEKDATA, tracer->child_pid, registers->rip, NULL) == -1)
        return false;
    name = browse_function_name(tracer->child_pid, registers->rip);
    if (!name)
        return false;
    fprintf(stderr, ENTERING_FUNCTION, name, registers->rip);
    return stack_push(&tracer->call_names, name);
}