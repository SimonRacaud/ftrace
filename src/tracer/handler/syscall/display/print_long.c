/*
** EPITECH PROJECT, 2021
** B-PSU-402-REN-4-1-strace-simon.racaud
** File description:
** print_pointer.c
*/

#include "syscall.h"

int print_long(unsigned long long int reg, __attribute__((unused)) pid_t child_pid)
{
    return fprintf(stderr, "%ld", (long) reg);
}

int print_ulong(unsigned long long int reg, __attribute__((unused)) pid_t child_pid)
{
    return fprintf(stderr, "%lu", (unsigned long) reg);
}
