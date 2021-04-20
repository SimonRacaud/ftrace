/*
** EPITECH PROJECT, 2021
** process_manage.c
** File description:
** process_manage
*/

#include "ftrace.h"

static bool call_pocessing(ftrace_t *data)
{
    long rip = 0;
    struct user_regs_struct regs;

    if (ptrace(PTRACE_GETREGS, data->pid, 0, &regs) == -1)
        return false;
    rip = ptrace(PTRACE_PEEKDATA, data->pid, regs.rip, NULL);
    if (rip == -1)
        return false;
    if ((rip & 0xFF) == 0xe8)
        call_enter_func(data, &regs, rip);
    /*if (!call_function(data, rip, &regs))
        return false;*/
    return true;
}

bool process_manage(ftrace_t *data)
{
    int ret = 0;
    struct rusage usage;

    wait4(data->pid, &ret, 0, &usage);
    if (ptrace(PTRACE_SETOPTIONS, data->pid, 0, PTRACE_O_TRACEEXIT) == -1)
        return false;
    while (data->running) {
        if (ptrace(PTRACE_SINGLESTEP, data->pid, NULL, NULL) == -1)
            return false;
        wait4(data->pid, &ret, 0, &usage);
        if (WIFEXITED(ret) || WIFSIGNALED(ret))
            break;
        if (!call_pocessing(data))
            return false;
    }
    printf("+++ exited with %i +++\n", (WIFEXITED(ret)) ? WEXITSTATUS(ret) : 0);
    return true;
}