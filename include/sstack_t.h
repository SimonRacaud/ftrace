/*
** EPITECH PROJECT, 2021
** B-PSU-402-REN-4-1-ftrace-simon.racaud
** File description:
** 22/04/2021 stack_t.h
*/

#ifndef SSTACK_T_H
#define SSTACK_T_H

typedef struct stack {
    struct stack *next;
    char *str;
} sstack_t;

#endif // SSTACK_T_H
