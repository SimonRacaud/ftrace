/*
** EPITECH PROJECT, 2021
** B-PSU-402-REN-4-1-ftrace-simon.racaud
** File description:
** 22/04/2021 process_instruction.c
*/

#include "app.h"

extern const instruction_t INSTR_HANDLERS[];

static int call_instruction_handler(
    intruct_handler func, tracer_t *tracer, registers_t *registers)
{
    if (func != NULL) {
        return func(tracer, registers);
    }
    return EXIT_SUCCESS;
}

int process_instruction(tracer_t *tracer)
{
    registers_t registers;
    uint16_t opcode;

    if (get_registers(&registers, tracer->child_pid) == EXIT_FAILURE)
        return EXIT_FAILURE;
    opcode = OPCODE(registers.rip);
    for (size_t i = 0; INSTR_HANDLERS[i].opcode != 0; i++) {
        if (opcode_match(opcode, INSTR_HANDLERS[i].opcode)) {
            return call_instruction_handler(
                INSTR_HANDLERS[i].handler, tracer, &registers);
        }
    }
    return trace_signal(tracer->child_pid);
}