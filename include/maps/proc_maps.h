/*
** EPITECH PROJECT, 2021
** B-PSU-402-REN-4-1-ftrace-simon.racaud
** File description:
** 26/04/2021 proc_maps.h
*/

#ifndef PROC_MAPS_H
#define PROC_MAPS_H

#define _GNU_SOURCE
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "proc_maps_line_t.h"
#include "proc_maps_match_t.h"

proc_maps_match_t *proc_maps_parser(pid_t child_pid, uint64_t rip);

// LINE
proc_maps_line_t *proc_maps_line_create(char *line);
void proc_maps_line_push(proc_maps_line_t *node, proc_maps_line_t **list);
void proc_maps_line_destroy(proc_maps_line_t *list);

// MATCH
void proc_maps_match_destroy(proc_maps_match_t *ptr);
proc_maps_match_t *proc_maps_match_create(void);

#endif // PROC_MAPS_H
