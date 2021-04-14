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
    {0, 0, NULL}
};