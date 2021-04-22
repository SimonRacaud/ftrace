/*
** EPITECH PROJECT, 2021
** B-PSU-402-REN-4-1-ftrace-simon.racaud
** File description:
** 22/04/2021 trace_binary.c
*/

#include "app.h"

static int tracer_setup(pid_t child_pid)
{
    if (wait4(child_pid, NULL, 0, NULL) == -1)
        return EXIT_FAILURE;
    if (ptrace(PTRACE_SETOPTIONS, child_pid, 0, PTRACE_O_TRACEEXIT) == -1)
        return EXIT_FAILURE;
    return EXIT_SUCCESS;
}

static void show_exit_status(int wstatus)
{
    int code = WIFEXITED(wstatus) ? WEXITSTATUS(wstatus) : 0;

    printf("+++ exited with %i +++\n", code);
}

int trace_binary(tracer_t *tracer)
{
    int wstatus = 0;
    int exit_value;

    if (tracer_setup(tracer->child_pid) == EXIT_FAILURE)
        return EXIT_FAILURE;
    while (tracer->is_running) {
        exit_value = step_forward(tracer->child_pid, &wstatus);
        if (exit_value == EXIT_FAILURE) {
            return EXIT_FAILURE;
        } else if (exit_value == EXIT_QUIT) {
            break;
        }
        if (process_instruction(tracer) == EXIT_FAILURE)
            return EXIT_FAILURE;
    }
    show_exit_status(wstatus);
    return EXIT_SUCCESS;
}