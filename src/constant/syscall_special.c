/*
** EPITECH PROJECT, 2021
** B-PSU-402-REN-4-1-ftrace-simon.racaud
** File description:
** 23/04/2021 syscall_special.c
*/

#include "syscall.h"
#include "syscall_special_t.h"

const size_t SYSCALL_SPECIAL_SIZE = 1;

const syscall_special_t SYSCALL_SPECIAL[] = {
    {
        .instruction = 0,
        .handler = &spec_handler_read
    }
};