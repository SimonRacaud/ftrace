/*
** EPITECH PROJECT, 2021
** B-PSU-402-REN-4-1-ftrace-simon.racaud
** File description:
** 23/04/2021 get_syscall_info.c
*/

#include "syscall.h"

extern const struct s_syscall g_syscalls[];

const syscall_t *get_syscall_info(uint64_t rax)
{
    for (size_t i = 0; g_syscalls[i].id != (uint64_t) -1; i++) {
        if (g_syscalls[i].id == rax) {
            return &(g_syscalls[i]);
        }
    }
    fprintf(stderr, MSG_NOT_SUPPORTED, BIN, rax);
    return NULL;
}