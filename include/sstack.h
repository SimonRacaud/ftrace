/*
** EPITECH PROJECT, 2021
** B-PSU-402-REN-4-1-ftrace-simon.racaud
** File description:
** 22/04/2021 stack.h
*/

#ifndef SSTACK_H
#define SSTACK_H

#include "stdlib.h"

#include "sstack_t.h"

int stack_push(sstack_t **stack_ptr, char *value);
char *stack_pop(sstack_t **stack_ptr);
void stack_destroy(sstack_t *stack);

#endif // SSTACK_H
