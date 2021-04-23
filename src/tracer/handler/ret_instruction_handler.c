/*
** EPITECH PROJECT, 2021
** B-PSU-402-REN-4-1-ftrace-simon.racaud
** File description:
** 23/04/2021 ret_instruction_handler.c
*/

#include "app.h"
#include "libc.h"

static const char *RETURN_MESSAGE = "Leaving function %s\n";

int ret_instruction_handler(tracer_t *tracer, NOTUSED registers_t *registers)
{
    char *call_name = stack_pop(&tracer->call_names);

    if (call_name == NULL) {
        call_name = strdup("");
        if (!call_name)
            return EXIT_FAILURE;
    }
    fprintf(stderr, RETURN_MESSAGE, call_name);
    free(call_name);
    return EXIT_SUCCESS;
}