/*
** EPITECH PROJECT, 2021
** B-PSU-402-REN-4-1-ftrace-simon.racaud
** File description:
** 22/04/2021 trace_signal.c
*/

#include "app.h"
#include "signal_name_t.h"

extern const signal_name_t SIGNAL_NAMES[];

int trace_signal(pid_t child_pid)
{
    siginfo_t signal = {0};

    if (ptrace(PTRACE_GETSIGINFO, child_pid, NULL, &signal) == -1)
        return EXIT_FAILURE;
    for (size_t i = 0; SIGNAL_NAMES[i].code; i++) {
        if (signal.si_signo == SIGTRAP) {
            continue;
        }
        if (SIGNAL_NAMES[i].code == signal.si_signo) {
            fprintf(stderr, "Received signal %s\n", SIGNAL_NAMES[i].name);
            break;
        }
    }
    return EXIT_SUCCESS;
}