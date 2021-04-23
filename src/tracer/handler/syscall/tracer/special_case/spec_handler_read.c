/*
** EPITECH PROJECT, 2021
** B-PSU-402-REN-4-1-strace-simon.racaud
** File description:
** trace_read.c
*/

#include "app.h"
#include "syscall.h"

static int error(const char *bin)
{
    perror(bin);
    return EXIT_FAILURE;
}

static int show_red_string(
    pid_t child_pid, uint *line_len, unsigned long long reg_value)
{
    registers_t post_syscall_regs = {0};
    uint size;

    if (ptrace(PTRACE_GETREGS, child_pid, NULL, &post_syscall_regs) == -1)
        return error("ptrace");
    size = print_substring(reg_value, child_pid, post_syscall_regs.rax);
    *line_len += size;
    return EXIT_SUCCESS;
}

static int show_syscall_args(const syscall_t *info, uint *line_length,
    registers_t *regs, pid_t child_pid)
{
    static size_t idx = 0;
    uint64_t reg_value;
    arg_t arg;

    reg_value = register_find(idx, regs);
    if (idx != 1) {
        arg.type = info->args[idx].printer.type;
        arg.value = reg_value;
        *line_length += print_register(&arg, child_pid, regs);
    } else {
        if (show_red_string(child_pid, line_length, reg_value))
            return EXIT_FAILURE;
    }
    if (idx != 2)
        *line_length += fprintf(stderr, ", ");
    if (++idx == 3)
        idx = 0;
    return EXIT_SUCCESS;
}

int spec_handler_read(registers_t *regs, pid_t child_pid,
    const syscall_t *info, uint line_length)
{
    if (show_syscall_args(info, &line_length, regs, child_pid) != EXIT_SUCCESS)
        return EXIT_FAILURE;
    if (step_forward(child_pid, NULL) != EXIT_SUCCESS)
        return EXIT_FAILURE;
    for (size_t i = 0; i < 2; i++) {
        if (show_syscall_args(info, &line_length, regs, child_pid)
            != EXIT_SUCCESS)
            return EXIT_FAILURE;
    }
    if (syscall_show_return_value(line_length, regs, child_pid, info))
        return EXIT_FAILURE;
    return EXIT_SUCCESS;
}