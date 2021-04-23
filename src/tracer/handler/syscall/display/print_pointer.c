/*
** EPITECH PROJECT, 2021
** B-PSU-402-REN-4-1-strace-simon.racaud
** File description:
** print_pointer.c
*/

#include "syscall.h"

int print_pointer(unsigned long long int reg,
    __attribute__((unused)) pid_t child_pid,
    __attribute__((unused)) const registers_t *regs)
{
    if (reg == 0) {
        return fprintf(stderr, "NULL");
    } else {
        return fprintf(stderr, "%p", (void *) reg);
    }
}
