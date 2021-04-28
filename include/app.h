/*
** EPITECH PROJECT, 2021
** B-PSU-402-REN-4-1-ftrace-simon.racaud
** File description:
** 22/04/2021 app.h
*/

#ifndef APP_H
#define APP_H

#define _GNU_SOURCE
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <gelf.h>

#ifdef EXIT_FAILURE
    #undef EXIT_FAILURE
#endif
#define EXIT_FAILURE 84
#define EXIT_QUIT    42

#define OPCODE(rip)      (0xFFFF & rip)
#define FIRST_BYTE(var)  (0xFF & var)
#define SECOND_BYTE(var) (0xFF00 & var)
#define RELATIVE_ADDR(addr, elf_start) (addr - elf_start)
#define IS_EMPTY(str) (str[0] == '\0')

#define NOTUSED __attribute__((unused))

#include "rmmod_t.h"
#include "instruction_t.h"
#include "tracer_t.h"

#include "elf_management.h"
#include "sstack.h"

int usage(int status, const char *bin);
bool show_usages(int argc, char **argv);

// TRACER
void tracer_init(tracer_t *tracer, char **argv);
void tracer_destroy(tracer_t *tracer);

int trace_binary(tracer_t *tracer);
int process_instruction(tracer_t *tracer);

int step_forward(pid_t child_pid, int *wstatus);
int get_registers(registers_t *dest, pid_t child_pid);
bool opcode_match(uint16_t opcode1, uint16_t opcode2);

int trace_signal(pid_t child_pid);

// TRACER - INSTRUCTION HANDLER
int ret_instruction_handler(tracer_t *tracer, NOTUSED registers_t *registers);

// BINARY
pid_t binary_launcher(char **command);

// RM/MOD
int execute_rmmode(tracer_t *tracer, registers_t *registers, int field_byte);

// DYNAMIC SYM
char *get_dynamic_name(Elf *elf,
size_t sh_link_dyntab, Elf_Data *data_dynsim, uint64_t addr);

// HANDLER
int ff_instruction_handler(tracer_t *tracer, registers_t *registers);
int e_eight_instruction_handler(tracer_t *tracer, registers_t *registers);
int syscall_instruction_handler(tracer_t *tracer, registers_t *registers);
int four_one_ff_instruction_handler(tracer_t *tracer, registers_t *registers);

#endif // APP_H
