/*
** EPITECH PROJECT, 2019
** binary_t.h
** File description:
** binary_t
*/

#ifndef BINARY_T_H
#define BINARY_T_H

#include <gelf.h>
#include <libelf.h>
#include <stdbool.h>

typedef struct binary_s
{
    int fd;
    Elf *elf;
    Elf_Scn *scn;
    bool have_symtab;
} binary_t;

#endif