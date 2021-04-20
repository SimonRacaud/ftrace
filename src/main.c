/*
** EPITECH PROJECT, 2021
** main.c
** File description:
** main
*/

#include "ftrace.h"

int main(int ac, char **av)
{
    ftrace_t data = {0};

    if (!init_struct(&data, ac, av))
        return ERROR;
    if (data.running)
        if (!process_manage(&data))
            return ERROR;
    destroy_binary(&data.bin);
    return SUCCESS;
}