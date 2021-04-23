/*
** EPITECH PROJECT, 2021
** B-PSU-402-REN-4-1-strace-simon.racaud
** File description:
** app_errno.h
*/

#ifndef APP_ERRNO_H_
#define APP_ERRNO_H_

#include <errno.h>
#include <stdio.h>
#include <string.h>
#include "syscall.h"

typedef struct errno_name
{
    int code;
    const char *name;
} errno_name_t;

#endif // APP_ERRNO_H_