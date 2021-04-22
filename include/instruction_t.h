/*
** EPITECH PROJECT, 2021
** B-PSU-402-REN-4-1-ftrace-simon.racaud
** File description:
** 22/04/2021 instruction_t.h
*/

#ifndef INSTRUCTION_T_H
#define INSTRUCTION_T_H

#include "tracer_t.h"
#include "libc.h"

typedef struct user_regs_struct registers_t;

typedef int (* intruct_handler)(tracer_t *, registers_t *);

typedef struct instruction {
    uint16_t opcode;
    intruct_handler handler;
} instruction_t;

#endif // INSTRUCTION_T_H
