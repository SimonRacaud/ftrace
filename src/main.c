/*
** EPITECH PROJECT, 2021
** main.c
** File description:
** main
*/

#include "ftrace.h"

static void destroy_struct(ftrace_t *data)
{
    for (size_t i = 0; data->leaving_list && data->leaving_list[i]; i++)
        free(data->leaving_list[i]);
    free(data->leaving_list);
}

int main(int ac, char **av)
{
    ftrace_t data = {0};

    if (!init_struct(&data, ac, av))
        return ERROR;
    if (data.running)
        if (!process_manage(&data))
            return ERROR;
    destroy_struct(&data);
    return SUCCESS;
}