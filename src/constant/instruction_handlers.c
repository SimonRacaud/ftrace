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
        .handler = &syscall_instruction_handler
    },
    {
        .opcode = 0x050f,
        .handler = &syscall_instruction_handler
    },
    {
        .opcode = 0xc3,
        .handler = &ret_instruction_handler
    },
    {
        .opcode = 0xcb,
        .handler = &ret_instruction_handler
    },
    {
        .opcode = 0xc2,
        .handler = &ret_instruction_handler
    },
    {
        .opcode = 0xca,
        .handler = &ret_instruction_handler
    },
    {
        .opcode = 0xe8,
        .handler = &e_eight_instruction_handler
    },
    {
        .opcode = 0x00ff,
        .handler = &ff_instruction_handler
    },
    {
        .opcode = 0xff41,
        .handler = &four_one_ff_instruction_handler
    },
    {
        .opcode = 0x0,
        .handler = NULL
    }
};