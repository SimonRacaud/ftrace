/*
** EPITECH PROJECT, 2021
** rmmod_manage.c
** File description:
** rmmod_manage
*/

#include "app.h"
#include "libc.h"

extern const char ENTERING_FUNCTION[];

static int get_name(tracer_t *tracer, unsigned long long addr)
{
    char *name = browse_function_name(tracer->child_pid, addr);

    if (!name)
        return EXIT_FAILURE;
    fprintf(stderr, ENTERING_FUNCTION, name, addr);
    return stack_push(&tracer->call_names, name);
}

int execute_rmmode(tracer_t *tracer, registers_t *registers, int field_byte)
{
    bool ret = false;
    rmmod_t *mode = (void *) &field_byte;

    switch (mode->reg)
    {
        case 0b10: ret = get_name(tracer, registers->rip); break;
        case 0b11: ret = get_name(tracer, registers->rip); break;
        default: ret = EXIT_SUCCESS; break;
    }
    return ret;
}