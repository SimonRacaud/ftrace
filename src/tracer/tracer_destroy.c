/*
** EPITECH PROJECT, 2021
** B-PSU-402-REN-4-1-ftrace-simon.racaud
** File description:
** 22/04/2021 tracer_destroy.c
*/

#include "app.h"

void tracer_destroy(tracer_t *tracer)
{
    if (tracer->call_names) {
        stack_destroy(tracer->call_names);
    }
}