/*
** EPITECH PROJECT, 2021
** B-PSU-402-REN-4-1-ftrace-simon.racaud
** File description:
** 26/04/2021 proc_maps_parser.c
*/

#include "proc_maps.h"

static FILE *open_file(pid_t child_pid)
{
    char *path;
    FILE *file;

    asprintf(&path, "/proc/%i/maps", child_pid);
    if (!path)
        return NULL;
    file = fopen(path, "r");
    free(path);
    return file;
}

static proc_maps_line_t *get_next_line(FILE *file)
{
    proc_maps_line_t *result;
    char *line = NULL;
    size_t size = 0;

    if (getline(&line, &size, file) == -1)
        return NULL;
    if (!line)
        return NULL;
    result = proc_maps_line_create(line);
    free(line);
    return result;
}

static void find_first_name_match_start(
    proc_maps_match_t *match, proc_maps_line_t *list, char *filepath)
{
    for (proc_maps_line_t *ptr = list; ptr != NULL; ptr = ptr->next) {
        if (strcmp(ptr->filepath, filepath) == 0) {
            match->name_match_start = ptr->start;
            return;
        }
    }
}

static void parse_map(proc_maps_match_t *match, FILE *file, uint64_t rip)
{
    proc_maps_line_t *list = NULL;
    proc_maps_line_t *ptr;

    do {
        ptr = get_next_line(file);
        if (!ptr)
            break;
        proc_maps_line_push(ptr, &list);
        if (ptr->start <= rip && rip <= ptr->end) {
            match->interval_match_filepath = strdup(ptr->filepath);
            find_first_name_match_start(match, list, ptr->filepath);
            break;
        }
    } while (ptr != NULL);
    if (list) {
        proc_maps_line_destroy(list);
    }
}

proc_maps_match_t *proc_maps_parser(pid_t child_pid, uint64_t rip)
{
    FILE *file = open_file(child_pid);
    proc_maps_match_t *result = proc_maps_match_create();

    if (!file || !result)
        return NULL;
    parse_map(result, file, rip);
    fclose(file);
    if (result->interval_match_filepath == NULL)
        return NULL;
    return result;
}