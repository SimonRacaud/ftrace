/*
** EPITECH PROJECT, 2021
** B-PSU-402-REN-4-1-ftrace-simon.racaud
** File description:
** 23/04/2021 register_find.c
*/

#include "syscall.h"

long long register_find(int i, registers_t *regs)
{
    switch (i) {
        case 0:
            return regs->rdi;
        case 1:
            return regs->rsi;
        case 2:
            return regs->rdx;
        case 3:
            return regs->r10;
        case 4:
            return regs->r8;
        case 5:
            return regs->r9;
        default:
            return 0;
    }
}
