/*
** EPITECH PROJECT, 2021
** B-PSU-402-REN-4-1-ftrace-simon.racaud
** File description:
** 22/04/2021 binary_launcher.c
*/

#include "app.h"

pid_t binary_launcher(char **command)
{
    int exit_status = EXIT_SUCCESS;
    pid_t child_pid = fork();

    if (child_pid == -1) {
        return -1;
    } else if (child_pid == 0) {
        exit_status = ptrace(PTRACE_TRACEME, 0, NULL, NULL);
        if (exit_status != -1) {
            raise(SIGSTOP);
            exit_status = execvp(command[0], command);
        }
        exit(exit_status);
    }
    return child_pid;
}