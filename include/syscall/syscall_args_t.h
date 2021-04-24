/*
** EPITECH PROJECT, 2021
** B-PSU-402-REN-4-1-ftrace-simon.racaud
** File description:
** 23/04/2021 syscall_args_t.h
*/

#ifndef SYSCALL_ARGS_T_H
#define SYSCALL_ARGS_T_H

#include "syscall_t.h"
#include "registers_t.h"

typedef struct syscall_args {
    const syscall_t *info;
    uint line_length;
    registers_t *regs;
    pid_t child_pid;
    bool detailled;
} syscall_args_t;

#endif // SYSCALL_ARGS_T_H
