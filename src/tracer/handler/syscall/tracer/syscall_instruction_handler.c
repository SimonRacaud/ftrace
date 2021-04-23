/*
** EPITECH PROJECT, 2021
** B-PSU-402-REN-4-1-strace-simon.racaud
** File description:
** tracer_process_syscall.c
*/

#include "app.h"
#include "syscall.h"
#include "tracer_t.h"

static int show_syscall(
    const syscall_t *info, registers_t *regs, pid_t child_pid)
{
    uint line_length = 0;

    print_syscall_name(info, &line_length);
    if (special_case_manager(regs, child_pid, info, line_length)
        == EXIT_SUCCESS) {
        return EXIT_SUCCESS;
    } else {
        if (syscall_show_args(&line_length, regs, child_pid, info)
            != EXIT_SUCCESS) {
            return EXIT_FAILURE;
        }
        if (syscall_show_return(line_length, regs, child_pid, info)
            != EXIT_SUCCESS) {
            return EXIT_FAILURE;
        }
    }
    return EXIT_SUCCESS;
}

int syscall_instruction_handler(
    tracer_t *tracer, NOTUSED registers_t *registers)
{
    const syscall_t *info = get_syscall_info(registers->rax);

    if (!info)
        return EXIT_SUCCESS;
    if (show_syscall(info, registers, tracer->child_pid)) {
        return EXIT_FAILURE;
    }
    return EXIT_SUCCESS;
}