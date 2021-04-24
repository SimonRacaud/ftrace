/*
** EPITECH PROJECT, 2021
** B-PSU-402-REN-4-1-strace-simon.racaud
** File description:
** app.h
*/

#ifndef APP_H_
#define APP_H_

#include <errno.h>
#include <signal.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/ptrace.h>
#include <sys/resource.h>
#include <sys/syscall.h>
#include <sys/time.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

#include "libc.h"
#include "arg_t.h"
#include "print_reg_t.h"
#include "registers_t.h"
#include "syscall_t.h"
#include "syscall_args_t.h"

#include "special_cases.h"

#ifdef EXIT_FAILURE
    #undef EXIT_FAILURE
#endif
#define EXIT_FAILURE      84
#define MSG_NOT_SUPPORTED "%s: syscall %lu not supported\n"
#define BIN               "ftrace"

#define IS_END_CALL(rax) rax == __NR_exit_group || rax == __NR_exit \
                                                || rax == __NR_pkey_free

/// CORE
void print_syscall_name(const syscall_t *info, uint *line_length);
int syscall_show_args(syscall_args_t *args);
int syscall_show_return(syscall_args_t *args);

int syscall_show_return_value(syscall_args_t *args);

/// UTILITY
long long register_find(int i, registers_t *regs);
const syscall_t *get_syscall_info(uint64_t rax);

/// SPECIAL CASES
int special_case_manager(syscall_args_t *args);
int spec_handler_read(syscall_args_t *args);

/// ERRNO
int errno_manager(arg_t *return_value);

/// DISPLAY
int print_register(arg_t *val, syscall_args_t *args);

int print_int(unsigned long long int reg, pid_t);
int print_pointer(unsigned long long int reg, pid_t);
int print_long(unsigned long long int reg, pid_t);
int print_ulong(unsigned long long int reg, pid_t);
int print_size_t(unsigned long long int reg, pid_t);
int print_ssize_t(unsigned long long int reg, pid_t);
int print_string(unsigned long long int reg, pid_t);

/// SPECIFIC CASE : DISPLAY
int print_substring(unsigned long long int reg, pid_t child_pid, ssize_t size);

#endif // APP_H_