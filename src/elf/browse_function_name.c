/*
** EPITECH PROJECT, 2021
** B-PSU-402-REN-4-1-ftrace-simon.racaud
** File description:
** 27/04/2021 browse_function_name.c
*/

#include "app.h"
#include "proc_maps.h"

char *browse_function_name(pid_t child_pid, uint64_t rip)
{
    proc_maps_match_t *match = proc_maps_parser(child_pid, rip);
    uint64_t addr;
    char *func_name = NULL;

    if (!match)
        return NULL;
    if (IS_EMPTY(match->interval_match_filepath) == false) {
        addr = rip - match->name_match_start;
        func_name =
            elf_parser_get_symbol_name(match->interval_match_filepath, addr);
        if (!func_name) {
            func_name = elf_parser_get_symbol_name(
                match->interval_match_filepath, rip);
        }
    }
    func_name = unknown_symbol_name_formatter(match, func_name, rip);
    proc_maps_match_destroy(match);
    return func_name;
}