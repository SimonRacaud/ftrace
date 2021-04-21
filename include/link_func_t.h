/*
** EPITECH PROJECT, 2019
** link_func_t.h
** File description:
** link_func_t
*/

#ifndef LINK_FUNC_T_H
#define LINK_FUNC_T_H

#include "libc.h"
#include "ftrace_t.h"

typedef struct link_func_s
{
    unsigned char first;
    unsigned char second;
    bool (*func)(ftrace_t *data, struct user_regs_struct *regs);
} link_func_t;

typedef struct data_link_s
{
    unsigned long long start;
    unsigned long long end;
    char *name;
} data_link_t;

typedef struct link_s
{
    int sig;
    char *val_sig;
} link_t;

#endif