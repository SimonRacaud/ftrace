/*
** EPITECH PROJECT, 2021
** B-PSU-402-REN-4-1-ftrace-simon.racaud
** File description:
** 26/04/2021 proc_maps_line_t.h
*/

#ifndef PROC_MAPS_LINE_T_H
#define PROC_MAPS_LINE_T_H

typedef struct proc_maps_line {
    uint64_t start;
    uint64_t end;
    char *filepath;
    struct proc_maps_line *next;
} proc_maps_line_t;

#endif // PROC_MAPS_LINE_T_H
