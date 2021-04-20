/*
** EPITECH PROJECT, 2021
** init_struct.c
** File description:
** init_struct
*/

#include "ftrace.h"

static bool forking_process(ftrace_t *data)
{
    int ret = 0;
    int pid_child = fork();

    if (pid_child == -1)
        return false;
    data->pid = pid_child;
    if (pid_child == 0) {
        ret = ptrace(PTRACE_TRACEME, 0, NULL, NULL);
        if (ret != -1) {
            raise(SIGSTOP);
            ret = execvp(*(data->av + 1), data->av + 1);
        }
        exit(ret);
    }
    return true;
}

bool init_struct(ftrace_t *data, int ac, char **av)
{
    if (ac < 2)
        return false;
    data->ac = ac;
    data->av = av;
    data->running = true;
    if (ac == 2 && !strcmp(av[1], HELP)) {
        data->running = false;
        display_help(av[0] + 2);
        return true;
    }
    if (!forking_process(data))
        return false;
    printf("%i == %i\n", data->pid, getpid());
    return init_binary(&data->bin, data->pid);
}