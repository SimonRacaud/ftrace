/*
** EPITECH PROJECT, 2021
** B-PSU-402-REN-4-1-ftrace-simon.racaud
** File description:
** 23/04/2021 arg_t.h
*/

#ifndef ARG_T_H
#define ARG_T_H

#include "syscall_t.h"


typedef struct arg {
    e_type type;
    unsigned long long int value;
} arg_t;

#endif // ARG_T_H
