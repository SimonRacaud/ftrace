/*
** EPITECH PROJECT, 2021
** B-PSU-402-REN-4-1-ftrace-simon.racaud
** File description:
** 26/04/2021 proc_maps_match.c
*/

#include "proc_maps.h"

proc_maps_match_t *proc_maps_match_create(void)
{
    proc_maps_match_t *ptr = malloc(sizeof(proc_maps_match_t));

    if (!ptr)
        return NULL;
    ptr->interval_match_filepath = NULL;
    ptr->name_match_start = 0;
    return ptr;
}

void proc_maps_match_destroy(proc_maps_match_t *ptr)
{
    if (ptr->interval_match_filepath)
        free(ptr->interval_match_filepath);
    free(ptr);
}

