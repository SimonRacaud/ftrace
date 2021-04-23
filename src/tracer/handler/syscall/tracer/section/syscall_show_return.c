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

int syscall_show_return_value(uint line_length, registers_t *regs,
    pid_t child_pid, const syscall_t *info)
{
    int status = EXIT_SUCCESS;
    arg_t arg = {.type = info->retval, .value = 0};

    if (get_registers(regs, child_pid))
        return EXIT_FAILURE;
    arg.value = regs->rax;
    print_padding(line_length);
    if (errno_manager(&arg) == EXIT_FAILURE) {
        status = print_register(&arg, child_pid, regs);
    }
    fprintf(stderr, "\n");
    return (status != -1) ? EXIT_SUCCESS : EXIT_FAILURE;
}

int syscall_show_return(uint line_length, registers_t *regs, pid_t child_pid,
    const syscall_t *info)
{
    if (info->noreturn == false) {
        if (regs->rax == __NR_exit_group || regs->rax == __NR_exit
            || regs->rax == __NR_pkey_free) {
            print_padding(line_length);
            fprintf(stderr, "?\n");
            return EXIT_SUCCESS;
        }
        if (step_forward(child_pid, NULL))
            return EXIT_FAILURE;
        return syscall_show_return_value(line_length, regs, child_pid, info);
    } else {
        fprintf(stderr, ")\n");
    }
    return EXIT_SUCCESS;
}