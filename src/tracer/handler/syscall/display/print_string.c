/*
** EPITECH PROJECT, 2021
** B-PSU-402-REN-4-1-strace-simon.racaud
** File description:
** print_string.c
*/

#include "syscall.h"

static const size_t MAX_SIZE = 32;

static int print_char_array(
    unsigned long long int reg, pid_t child_pid, size_t *idx)
{
    size_t size = 0;
    char c = -1;

    for (*idx = 0; c != '\0' && (*idx) < MAX_SIZE; (*idx)++) {
        c = ptrace(PTRACE_PEEKTEXT, child_pid, reg + (*idx), NULL);
        if (c == -1)
            return -1;
        else if (c == '\0')
            break;
        if (isprint(c)) {
            size += fprintf(stderr, "%c", c);
        } else {
            size += fprintf(stderr, "\\%o", c);
        }
    }
    return size;
}

int print_string(unsigned long long int reg, pid_t child_pid)
{
    size_t idx = 0;
    size_t size = 0;

    if (reg == 0) {
        size += fprintf(stderr, "NULL");
        return -1;
    }
    size += fprintf(stderr, "\"");
    size += print_char_array(reg, child_pid, &idx);
    size += fprintf(stderr, "\"");
    if (idx == MAX_SIZE - 1) {
        size += fprintf(stderr, "...");
    }
    return size;
}