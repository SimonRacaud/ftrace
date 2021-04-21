/*
** EPITECH PROJECT, 2021
** call_function.c
** File description:
** call_function
*/

#include "ftrace.h"

extern const link_t SIGNAL_LINK[];

/*
** DOC https://github.com/gaffe23/linux-inject/blob/master/ptrace.c
*/

bool signal_func(ftrace_t *data)
{
    siginfo_t signal = {0};

    if (ptrace(PTRACE_GETSIGINFO, data->pid, NULL, &signal) == -1)
        return false;
    for (size_t i = 0; SIGNAL_LINK[i].val_sig; i++) {
        if (signal.si_signo == SIGTRAP)
            continue;
        if (SIGNAL_LINK[i].sig == signal.si_signo) {
            fprintf(stderr, "Received signal %s\n", SIGNAL_LINK[i].val_sig);
            break;
        }
    }
    return true;
}