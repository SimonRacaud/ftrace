/*
** EPITECH PROJECT, 2021
** B-PSU-402-REN-4-1-strace-simon.racaud
** File description:
** syscall_show_return.c
*/

#include "syscall.h"
#include "app.h"

static void print_padding(uint line_length)
{
    line_length += fprintf(stderr, ")");
    for (size_t i = line_length + 1; i < 40; i++) {
        fprintf(stderr, " ");
    }
    fprintf(stderr, " = ");
}

int syscall_show_return_value(syscall_args_t *args)
{
    int status = EXIT_SUCCESS;
    arg_t param = {.type = args->info->retval, .value = 0};

    if (get_registers(args->regs, args->child_pid))
        return EXIT_FAILURE;
    param.value = args->regs->rax;
    print_padding(args->line_length);
    if (errno_manager(&param) == EXIT_FAILURE) {
        status = print_register(&param, args);
    }
    fprintf(stderr, "\n");
    return (status != -1) ? EXIT_SUCCESS : EXIT_FAILURE;
}

int syscall_show_return(syscall_args_t *args)
{
    if (args->info->noreturn == false) {
        if (IS_END_CALL(args->regs->rax)) {
            print_padding(args->line_length);
            fprintf(stderr, "?\n");
            return EXIT_SUCCESS;
        }
        if (step_forward(args->child_pid, NULL))
            return EXIT_FAILURE;
        return syscall_show_return_value(args);
    } else {
        fprintf(stderr, ")\n");
    }
    return EXIT_SUCCESS;
}