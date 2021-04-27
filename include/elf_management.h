/*
** EPITECH PROJECT, 2021
** B-PSU-402-REN-4-1-ftrace-simon.racaud
** File description:
** 27/04/2021 elf_management.h
*/

#ifndef ELF_MANAGEMENT_H
#define ELF_MANAGEMENT_H

#include "proc_maps_match_t.h"

char *browse_function_name(pid_t child_pid, uint64_t rip);
char *elf_parser_get_symbol_name(char *elf_filepath, uint64_t addr);
char *unknown_symbol_name_formatter(
    proc_maps_match_t *match, char *func_name, uint64_t rip);

#endif // ELF_MANAGEMENT_H
