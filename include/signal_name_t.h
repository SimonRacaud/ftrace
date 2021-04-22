/*
** EPITECH PROJECT, 2021
** B-PSU-402-REN-4-1-ftrace-simon.racaud
** File description:
** 22/04/2021 signal_name_t.h
*/

#ifndef SIGNAL_NAME_T_H
#define SIGNAL_NAME_T_H

#include <signal.h>
#include <stddef.h>

typedef struct signal_name {
    int code;
    const char *name;
} signal_name_t;

#endif // SIGNAL_NAME_T_H
