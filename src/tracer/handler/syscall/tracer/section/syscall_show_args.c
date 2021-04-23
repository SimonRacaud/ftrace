/*
** EPITECH PROJECT, 2021
** B-PSU-402-REN-4-1-strace-simon.racaud
** File description:
** syscall_show_args.c
*/

#include "syscall.h"

static int print_syscall_params(struct s_syscall_arg sys_arg, pid_t child_pid,
    unsigned long long reg_value)
{
    int size;
    arg_t arg;

    if (!sys_arg.custom) {
        arg.type = sys_arg.printer.type;
        arg.value = reg_value;
        size = print_register(&arg, child_pid, NULL);
    } else {
        size = sys_arg.printer.callback(reg_value, child_pid, NULL);
    }
    return size;
}

int syscall_show_args(uint *line_length, registers_t *regs, pid_t child_pid,
    const syscall_t *info)
{
    unsigned long long reg_value;
    int size;

    for (size_t i = 0; i < info->argc; i++) {
        if (i != 0) {
            *line_length += fprintf(stderr, ", ");
        }
        reg_value = register_find(i, regs);
        size = print_syscall_params(info->args[i], child_pid, reg_value);
        if (size == -1)
            return EXIT_FAILURE;
        *line_length += size;
    }
    return EXIT_SUCCESS;
}