/*
** EPITECH PROJECT, 2021
** B-PSU-402-REN-4-1-strace-simon.racaud
** File description:
** ernno_handler.c
*/

#include "app_errno.h"

extern const errno_name_t ERRNO_NAMES[];

static const char *get_errno_name(int code)
{
    for (size_t i = 0; ERRNO_NAMES[i].name != NULL; i++) {
        if (ERRNO_NAMES[i].code == code) {
            return ERRNO_NAMES[i].name;
        }
    }
    return "????";
}

int errno_manager(arg_t *return_value)
{
    const char *name;
    int code = -((int) return_value->value);

    if ((return_value->type != T_INTEGER && return_value->type != T_SSIZE_T)
        || (-code) >= 0) {
        return EXIT_FAILURE;
    }
    name = get_errno_name(code);
    fprintf(stderr, "-1 %s (%s)", name, strerror(code));
    return EXIT_SUCCESS;
}