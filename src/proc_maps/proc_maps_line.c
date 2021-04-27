/*
** EPITECH PROJECT, 2021
** B-PSU-402-REN-4-1-ftrace-simon.racaud
** File description:
** 26/04/2021 proc_maps_line.c
*/

#include "proc_maps.h"
#include "utility.h"

proc_maps_line_t *proc_maps_line_create(char *line)
{
    char **parsed_line = my_str_to_array(line);
    char *filepath;
    proc_maps_line_t *result = malloc(sizeof(proc_maps_line_t));
    size_t size = 0;

    if (!parsed_line || !result)
        return NULL;
    while (parsed_line[size] != NULL)
        size++;
    if (size == 0)
        return NULL;
    sscanf(parsed_line[0], "%lx-%lx", &result->start, &result->end);
    filepath = (size == 6) ? parsed_line[5] : "";
    result->filepath = strdup(filepath);
    for (size_t i = 0; parsed_line[i]; i++)
        free(parsed_line[i]);
    free(parsed_line);
    return result;
}

void proc_maps_line_push(proc_maps_line_t *node, proc_maps_line_t **list)
{
    proc_maps_line_t *ptr = *list;

    if (*list == NULL) {
        *list = node;
    } else {
        while (ptr->next != NULL)
            ptr = ptr->next;
        ptr->next = node;
    }
    node->next = NULL;
}

void proc_maps_line_destroy(proc_maps_line_t *list)
{
    proc_maps_line_t *next = NULL;

    for (proc_maps_line_t *ptr = list; ptr != NULL; ptr = next) {
        next = ptr->next;
        if (ptr->filepath)
            free(ptr->filepath);
        free(ptr);
    }
}