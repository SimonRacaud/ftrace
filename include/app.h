/*
** EPITECH PROJECT, 2021
** B-PSU-402-REN-4-1-ftrace-simon.racaud
** File description:
** 22/04/2021 app.h
*/

#ifndef APP_H
#define APP_H

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#ifdef EXIT_FAILURE
    #undef EXIT_FAILURE
#endif
#define EXIT_FAILURE 84
#define EXIT_QUIT    42

#define OPCODE(rip)      (0xFFFF & rip)
#define FIRST_BYTE(var)  (0xFF & var)
#define SECOND_BYTE(var) (0x00FF & var)

#define NOTUSED __attribute__((unused))

#include "sstack.h"
#include "instruction_t.h"
#include "tracer_t.h"

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

#endif // APP_H
