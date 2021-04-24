/*
** EPITECH PROJECT, 2021
** B-PSU-402-REN-4-1-ftrace-simon.racaud
** File description:
** 23/04/2021 syscall_special_t.h
*/

#ifndef SYSCALL_SPECIAL_T_H
#define SYSCALL_SPECIAL_T_H

#include "syscall_args_t.h"

typedef int (*special_case_handler)(syscall_args_t *args);

typedef struct syscall_special {
    uint64_t instruction;
    special_case_handler handler;
} syscall_special_t;

#endif // SYSCALL_SPECIAL_T_H
