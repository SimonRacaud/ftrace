/*
** EPITECH PROJECT, 2021
** B-PSU-402-REN-4-1-ftrace-simon.racaud
** File description:
** 22/04/2021 tracer_t.h
*/

#ifndef TRACER_T_H
#define TRACER_T_H

#include "sstack_t.h"
#include <sys/types.h>
#include <stdbool.h>

typedef struct tracer {
    char **command;
    pid_t child_pid;
    bool is_running;
    sstack_t *call_names;
} tracer_t;

#endif // TRACER_T_H
