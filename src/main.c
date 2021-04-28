/*
** EPITECH PROJECT, 2021
** B-PSU-402-REN-4-1-ftrace-simon.racaud
** File description:
** 22/04/2021 main.c
*/

#include "app.h"

static const int ARGC_NEEDED = 2;

int main(int argc, char **argv)
{
    tracer_t tracer;

    if (show_usages(argc, argv)) {
        return usage(EXIT_SUCCESS, argv[0]);
    } else if (argc < ARGC_NEEDED) {
        return usage(EXIT_FAILURE, argv[0]);
    }
    tracer_init(&tracer, argv);
    tracer.child_pid = binary_launcher(tracer.command);
    if (tracer.child_pid == -1)
        return EXIT_FAILURE;
    if (trace_binary(&tracer) == EXIT_FAILURE)
        return EXIT_FAILURE;
    tracer_destroy(&tracer);
    return EXIT_SUCCESS;
}