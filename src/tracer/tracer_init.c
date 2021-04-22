/*
** EPITECH PROJECT, 2021
** B-PSU-402-REN-4-1-ftrace-simon.racaud
** File description:
** 22/04/2021 tracer_init.c
*/

#include "app.h"

void tracer_init(tracer_t *tracer, char **argv)
{
    tracer->command = &argv[1];
    tracer->child_pid = -1;
    tracer->is_running = true;
    tracer->call_names = NULL;
}