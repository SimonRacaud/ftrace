/*
** EPITECH PROJECT, 2021
** B-PSU-402-REN-4-1-ftrace-simon.racaud
** File description:
** 27/04/2021 unknown_symbol_name_formatter.c
*/

#include "app.h"

char *unknown_symbol_name_formatter(
    proc_maps_match_t *match, char *func_name, uint64_t rip)
{
    char *not_found_name;

    if (func_name)
        return func_name;
    asprintf(&not_found_name, "func_0x%lX@%s", rip,
        match->interval_match_filepath);
    return not_found_name;
}