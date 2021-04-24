/*
** EPITECH PROJECT, 2021
** special_cases.h
** File description:
** functions to print specific syscalls informations
*/

#ifndef STRACE_SPECIAL_CASES_H
#define STRACE_SPECIAL_CASES_H

#include <stddef.h>
#include <sys/stat.h>
#include <sys/sysmacros.h>
#include "syscall_args_t.h"

int spe_stat(unsigned long long int reg, pid_t child_pid);

#endif // STRACE_SPECIAL_CASES_H