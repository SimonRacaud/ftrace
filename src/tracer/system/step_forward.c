/*
** EPITECH PROJECT, 2021
** B-PSU-402-REN-4-1-ftrace-simon.racaud
** File description:
** 22/04/2021 step_forward.c
*/

#include "app.h"
#include "libc.h"

int step_forward(pid_t child_pid, int *wstatus)
{
    if (ptrace(PTRACE_SINGLESTEP, child_pid, NULL, NULL) == -1)
        return EXIT_FAILURE;
    if (wait4(child_pid, wstatus, 0, NULL) == -1)
        return EXIT_FAILURE;
    if (wstatus && (WIFEXITED(*wstatus) || WIFSIGNALED(*wstatus)))
        return EXIT_QUIT;
    return EXIT_SUCCESS;
}