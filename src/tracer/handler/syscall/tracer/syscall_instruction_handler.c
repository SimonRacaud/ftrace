/*
** EPITECH PROJECT, 2021
** B-PSU-402-REN-4-1-strace-simon.racaud
** File description:
** tracer_process_syscall.c
*/

#include "app.h"
#include "syscall.h"
#include "tracer_t.h"

static int show_syscall(syscall_args_t *args)
{
    print_syscall_name(args->info, &args->line_length);
    if (special_case_manager(args) == EXIT_SUCCESS) {
        return EXIT_SUCCESS;
    } else {
        if (syscall_show_args(args) != EXIT_SUCCESS) {
            return EXIT_FAILURE;
        }
        if (syscall_show_return(args) != EXIT_SUCCESS) {
            return EXIT_FAILURE;
        }
    }
    return EXIT_SUCCESS;
}

static void init_args(
    syscall_args_t *args, tracer_t *tracer, registers_t *registers)
{
    args->info = get_syscall_info(registers->rax);
    args->regs = registers;
    args->child_pid = tracer->child_pid;
    args->line_length = false;
}

int syscall_instruction_handler(tracer_t *tracer, registers_t *registers)
{
    syscall_args_t args;

    init_args(&args, tracer, registers);
    if (!args.info)
        return EXIT_SUCCESS;
    if (show_syscall(&args)) {
        return EXIT_FAILURE;
    }
    return EXIT_SUCCESS;
}