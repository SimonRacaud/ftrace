/*
** EPITECH PROJECT, 2021
** call_function.c
** File description:
** call_function
*/

#include "ftrace.h"

extern const link_func_t REDIRECTION[];

bool call_function(ftrace_t *data, long rip, struct user_regs_struct *regs)
{
    unsigned char first = (unsigned) 0xFF & rip;
    unsigned char second = ((unsigned) 0xFF00 & rip) >> 8;

    for (size_t i = 0; REDIRECTION[i].first && REDIRECTION[i].second; i++) {
        if (REDIRECTION[i].first == first && REDIRECTION[i].second == second) {
            if ((REDIRECTION[i].func)) {
                return REDIRECTION[i].func(data, regs);
            } else {
                return true;
            }
        }
    }
    return true;
}