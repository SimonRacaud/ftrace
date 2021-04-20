/*
** EPITECH PROJECT, 2021
** constante.c
** File description:
** constante
*/

#include "ftrace.h"

const link_func_t REDIRECTION[] =
{
    {0xCD, 0x80, call_syscall},
    {0x0F, 0x05, call_syscall},
    {0xe8, 0, call_enter_func},
    //{0xff, 0, call_enter_func},
    //{0xff2, 0, NULL},
    {0, 0, NULL}
};