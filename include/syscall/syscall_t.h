/*
** EPITECH PROJECT, 2021
** B-PSU-402-REN-4-1-strace-simon.racaud
** File description:
** strace.h
*/

#ifndef STRACE_H_
#define STRACE_H_

#include <stdbool.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/user.h>

#define STRACE_SYSCALL_ARGS_MAX 6

typedef int (*t_printer)(unsigned long long int, pid_t);

typedef enum e_type
{
    T_DEFAULT,
    T_INTEGER,
    T_POINTER,
    T_STRING,
    T_LONG,
    T_ULONG,
    T_SIZE_T,
    T_SSIZE_T,
} e_type;

struct s_syscall_arg
{
    bool custom;
    union {
        enum e_type type;
        t_printer callback;
    } printer;
};

typedef struct s_syscall
{
    unsigned long long id;
    const char *name;
    bool noreturn;
    enum e_type retval;
    size_t argc;
    struct s_syscall_arg args[STRACE_SYSCALL_ARGS_MAX];
} syscall_t;

#endif