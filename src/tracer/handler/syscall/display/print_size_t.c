/*
** EPITECH PROJECT, 2021
** B-PSU-402-REN-4-1-strace-simon.racaud
** File description:
** print_size_t.c
*/

#include "syscall.h"

int print_size_t(unsigned long long int reg,
__attribute__((unused)) pid_t child_pid)
{
    return fprintf(stderr, "%llu", (unsigned long long int) reg);
}

int print_ssize_t(unsigned long long int reg,
__attribute__((unused)) pid_t child_pid)
{
    return fprintf(stderr, "%lld", reg);
}