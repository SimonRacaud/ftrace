/*
** EPITECH PROJECT, 2021
** B-PSU-402-REN-4-1-strace-simon.racaud
** File description:
** print_register.c
*/

#include "syscall.h"

static const print_reg_t INDEX[] = {
    {T_INTEGER, &print_int},
    {T_POINTER, &print_pointer},
    {T_STRING, &print_string},
    {T_LONG, &print_long},
    {T_ULONG, &print_ulong},
    {T_SIZE_T, print_size_t},
    {T_SSIZE_T, print_ssize_t},
    {T_DEFAULT, NULL}
};

static inline int print_default(unsigned long long int reg,
    __attribute__((unused)) pid_t child_pid)
{
    return fprintf(stderr, "0x%llx", reg);
}

int print_register(arg_t *val, syscall_args_t *args)
{
    if (args->detailled == false) {
        return print_default(val->value, args->child_pid);
    } else {
        for (size_t i = 0; INDEX[i].func != NULL; i++) {
            if (INDEX[i].type == val->type) {
                return INDEX[i].func(val->value, args->child_pid);
            }
        }
        return print_default(val->value, args->child_pid);
    }
}