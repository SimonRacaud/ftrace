/*
** EPITECH PROJECT, 2021
** call_syscall.c
** File description:
** call_syscall
*/

#include "ftrace.h"

extern const struct s_syscall g_syscalls[];

static struct s_syscall get_syscall_struct(size_t syscall)
{
    size_t i = 0;

    if (g_syscalls[syscall].id == syscall)
        return g_syscalls[syscall];
    for (i = 0; g_syscalls[i].id != (unsigned long long) -1; i++)
        if (g_syscalls[i].id == syscall)
            break;
    return g_syscalls[i];
}

static void display_basic(unsigned long long int val)
{
    fprintf(stderr, "0x%llx", val);
}

static bool display_end_syscall(ftrace_t *data, bool have_return)
{
    int ret = 0;
    struct user_regs_struct regs;

    if (ptrace(PTRACE_SINGLESTEP, data->pid, NULL, NULL) == -1)
        return false;
    wait4(data->pid, &ret, 0, NULL);
    if (WIFEXITED(ret) || WIFSIGNALED(ret)) {
        data->running = false;
        return true;
    }
    if (ptrace(PTRACE_GETREGS, data->pid, 0, &regs) == -1)
        return false;
    if (have_return)
        fprintf(stderr, ") = 0x%llx\n", regs.rax);
    else
        fprintf(stderr, ") = ?\n");
    return true;
}

bool call_syscall(ftrace_t *data, struct user_regs_struct *regs, long rip)
{
    const struct s_syscall who = get_syscall_struct(regs->rax);
    const unsigned long long params[STRACE_SYSCALL_ARGS_MAX] = {
        regs->rdi, regs->rsi, regs->rdx, regs->r10, regs->r8, regs->r9
    };

    (void) rip;
    fprintf(stderr, "Syscall %s(", who.name);
    for (size_t i = 0; i < who.argc; i++) {
        display_basic(params[i]);
        if (i + 1 < who.argc)
            fprintf(stderr, ", ");
    }
    if (!display_end_syscall(data, !who.noreturn))
        return false;
    fflush(stderr);
    return true;
}