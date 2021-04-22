/*
** EPITECH PROJECT, 2021
** strace_source
** File description:
** strace_source
*/

#ifndef STRACE_SOURCE_H_
#define STRACE_SOURCE_H_

#include "../include/libc.h"
#include "ftrace_t.h"

#define STRACE_SYSCALL_ARGS_MAX 6
typedef unsigned long long int sssize_t;

typedef int (*t_printer)(
    sssize_t,
    pid_t,
    const struct user_regs_struct *,
    const ftrace_t *
);

enum e_type
{
    T_DEFAULT = 0,
    T_INTEGER = 1,
    T_POINTER = 2,
    T_STRING = 3,
    T_LONG = 4,
    T_ULONG = 5,
    T_SIZE_T = 6,
    T_SSIZE_T = 7,
    T_OPEN_FLAG = 8,
    T_MMAP_FLAG = 9,
    T_LSEEK_FLAG= 10,
    T_PROT_FLAG= 11,
    T_ACCESS_FLAG= 12,
    T_FD_AT = 13,
    T_STAT_STRUCT = 14
};

struct s_syscall_arg
{
    bool custom;
    union
    {
        enum e_type type;
        t_printer callback;
    } printer;
};

struct s_syscall
{
    unsigned long long id;
    const char  *name;
    bool noreturn;
    enum e_type retval;
    size_t argc;
    struct s_syscall_arg args[STRACE_SYSCALL_ARGS_MAX];
};

#endif