/*
** EPITECH PROJECT, 2021
** constante.c
** File description:
** constante
*/

#include "ftrace.h"

const link_func_t REDIRECTION[] =
{
    {0xCD, 0x80, NULL},
    {0x0F, 0x05, NULL},
    {0, 0, NULL}
};