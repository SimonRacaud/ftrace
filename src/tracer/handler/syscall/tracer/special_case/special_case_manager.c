/*
** EPITECH PROJECT, 2021
** B-PSU-402-REN-4-1-ftrace-simon.racaud
** File description:
** 23/04/2021 special_case_manager.c
*/

#include "syscall.h"
#include "syscall_special_t.h"

extern const size_t SYSCALL_SPECIAL_SIZE;
extern const syscall_special_t SYSCALL_SPECIAL[];

int special_case_manager(syscall_args_t *args)
{
    registers_t *registers = args->regs;

    for (size_t i = 0; i < SYSCALL_SPECIAL_SIZE; i++) {
        if (SYSCALL_SPECIAL[i].instruction == registers->rax
            && SYSCALL_SPECIAL[i].handler != NULL) {
            return SYSCALL_SPECIAL[i].handler(args);
        }
    }
    return EXIT_FAILURE;
}