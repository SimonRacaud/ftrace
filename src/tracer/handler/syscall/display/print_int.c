/*
** EPITECH PROJECT, 2021
** B-PSU-402-REN-4-1-strace-simon.racaud
** File description:
** print_int.c
*/

#include "syscall.h"

int print_int(unsigned long long int reg,
__attribute__((unused)) pid_t child_pid)
{
    return fprintf(stderr, "%lld", reg);
}
