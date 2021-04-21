/*
** EPITECH PROJECT, 2021
** call_function.c
** File description:
** call_function
*/

#include "ftrace.h"

extern const link_func_t REDIRECTION[];

static bool match_with(size_t i, unsigned char first, unsigned char second)
{
    if (REDIRECTION[i].first == first && REDIRECTION[i].second == second)
        return true;
    if (REDIRECTION[i].first == first && !REDIRECTION[i].second)
        return true;
    return false;
}

bool call_function(ftrace_t *data, long rip, struct user_regs_struct *regs)
{
    unsigned char first = (unsigned) 0xFF & rip;
    unsigned char second = ((unsigned) 0xFF00 & rip) >> 8;

    for (size_t i = 0; REDIRECTION[i].first || REDIRECTION[i].second; i++) {
        if (match_with(i, first, second)) {
            if ((REDIRECTION[i].func)) {
                return REDIRECTION[i].func(data, regs, rip);
            } else {
                return true;
            }
        }
    }
    return signal_func(data);
}