/*
** EPITECH PROJECT, 2019
** ftrace_t.h
** File description:
** ftrace_t
*/

#ifndef FTRACE_T_H
#define FTRACE_T_H

#include <stdbool.h>

typedef struct ftrace_s
{
    int ac;
    int pid;
    char **av;
    bool running;
} ftrace_t;

#endif