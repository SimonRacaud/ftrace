/*
** EPITECH PROJECT, 2021
** B-PSU-402-REN-4-1-ftrace-simon.racaud
** File description:
** 22/04/2021 instruction_handler.c
*/

#include "instruction_t.h"
#include "app.h"

const instruction_t INSTR_HANDLERS[] = {
    {
        .opcode = 0x80cd,
        .handler = NULL//&syscall_instruction_handler
    },
    {
        .opcode = 0x050f,
        .handler = NULL//&syscall_instruction_handler
    },
    {
        .opcode = 0xc3,
        .handler = NULL//&ret_instruction_handler
    },
    {
        .opcode = 0xcb,
        .handler = NULL//&ret_instruction_handler
    },
    {
        .opcode = 0xc2,
        .handler = NULL//&ret_instruction_handler
    },
    {
        .opcode = 0xca,//&ret_instruction_handler
        .handler = NULL
    },
    {
        .opcode = 0xe8,
        .handler = NULL//&e_eight_instruction_handler
    },
    {
        .opcode = 0xff,
        .handler = NULL//&ff_instruction_handler
    },
    {
        .opcode = 0x9a,
        .handler = NULL//&nine_a_instruction_handler
    },
    {
        .opcode = 0x0,
        .handler = NULL
    }
};