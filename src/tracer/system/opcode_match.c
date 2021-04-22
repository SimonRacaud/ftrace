/*
** EPITECH PROJECT, 2021
** B-PSU-402-REN-4-1-ftrace-simon.racaud
** File description:
** 22/04/2021 opcode_match.c
*/

#include "app.h"

bool opcode_match(uint16_t opcode1, uint16_t opcode2)
{
    if (opcode1 == opcode2) {
        return true;
    } else if (FIRST_BYTE(opcode1) == FIRST_BYTE(opcode2)
               && SECOND_BYTE(opcode2) == 0) {
        return true;
    }
    return false;
}