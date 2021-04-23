/*
** EPITECH PROJECT, 2021
** B-PSU-402-REN-4-1-ftrace-simon.racaud
** File description:
** 23/04/2021 print_reg_t.h
*/

#ifndef PRINT_REG_T_H
#define PRINT_REG_T_H

#include "syscall_t.h"

typedef struct print_reg {
    e_type type;
    t_printer func;
} print_reg_t;

#endif // PRINT_REG_T_H
