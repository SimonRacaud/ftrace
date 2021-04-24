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

static int show_syscall_args(syscall_args_t *args)
{
    static size_t idx = 0;
    uint64_t reg_value;
    arg_t param;

    reg_value = register_find(idx, args->regs);
    if (idx != 1) {
        param.type = args->info->args[idx].printer.type;
        param.value = reg_value;
        args->line_length += print_register(&param, args);
    } else {
        if (show_red_string(args->child_pid, &args->line_length, reg_value))
            return EXIT_FAILURE;
    }
    if (idx != 2)
        args->line_length += fprintf(stderr, ", ");
    if (++idx == 3)
        idx = 0;
    return EXIT_SUCCESS;
}

int spec_handler_read(syscall_args_t *args)
{
    if (show_syscall_args(args) != EXIT_SUCCESS)
        return EXIT_FAILURE;
    if (step_forward(args->child_pid, NULL) != EXIT_SUCCESS)
        return EXIT_FAILURE;
    for (size_t i = 0; i < 2; i++) {
        if (show_syscall_args(args) != EXIT_SUCCESS)
            return EXIT_FAILURE;
    }
    if (syscall_show_return_value(args))
        return EXIT_FAILURE;
    return EXIT_SUCCESS;
}