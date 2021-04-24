/*
** EPITECH PROJECT, 2021
** B-PSU-402-REN-4-1-strace-simon.racaud
** File description:
** syscall_show_args.c
*/

#include "syscall.h"

static int print_syscall_params(struct s_syscall_arg sys_arg,
    syscall_args_t *args, unsigned long long reg_value)
{
    int size;
    arg_t param;

    if (!sys_arg.custom) {
        param.type = sys_arg.printer.type;
        param.value = reg_value;
        size = print_register(&param, args);
    } else {
        size = sys_arg.printer.callback(reg_value, args->child_pid);
    }
    return size;
}

int syscall_show_args(syscall_args_t *args)
{
    unsigned long long reg_value;
    int size;

    for (size_t i = 0; i < args->info->argc; i++) {
        if (i != 0) {
            args->line_length += fprintf(stderr, ", ");
        }
        reg_value = register_find(i, args->regs);
        size = print_syscall_params(args->info->args[i], args, reg_value);
        if (size == -1)
            return EXIT_FAILURE;
        args->line_length += size;
    }
    return EXIT_SUCCESS;
}