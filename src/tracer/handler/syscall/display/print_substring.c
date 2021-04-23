/*
** EPITECH PROJECT, 2021
** B-PSU-402-REN-4-1-strace-simon.racaud
** File description:
** print_string.c
*/

#include "syscall.h"

static const size_t MAX_SIZE = 32;

static int print_char_array(
    unsigned long long int reg, pid_t child_pid, size_t *idx, size_t size)
{
    size_t len = 0;
    char c = -1;

    for (*idx = 0; (*idx) < size && (*idx) < MAX_SIZE; (*idx)++) {
        c = ptrace(PTRACE_PEEKTEXT, child_pid, reg + (*idx), NULL);
        if (c == -1) {
            return -1;
        } else if (c == '\0') {
            break;
        }
        if (isprint(c)) {
            len += fprintf(stderr, "%c", c);
        } else {
            len += fprintf(stderr, "\\%o", c);
        }
    }
    return len;
}

int print_substring(unsigned long long int reg, pid_t child_pid, ssize_t size)
{
    size_t idx = 0;
    size_t len = 0;

    if (size < 0)
        size = 0;
    if (reg == 0) {
        return fprintf(stderr, "NULL");
    }
    len += fprintf(stderr, "\"");
    len += print_char_array(reg, child_pid, &idx, size);
    len += fprintf(stderr, "\"");
    if (idx == MAX_SIZE - 1) {
        len += fprintf(stderr, "...");
    }
    return len;
}
