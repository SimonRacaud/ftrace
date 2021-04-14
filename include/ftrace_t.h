/*
** EPITECH PROJECT, 2019
** ftrace_t.h
** File description:
** ftrace_t
*/

#ifndef FTRACE_T_H
#define FTRACE_T_H

typedef struct ftrace_s
{
    int ac;
    char **av;
    int pid;
} ftrace_t;

#endif