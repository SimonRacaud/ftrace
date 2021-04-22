/*
** EPITECH PROJECT, 2021
** B-PSU-402-REN-4-1-ftrace-simon.racaud
** File description:
** 22/04/2021 signal_names.c
*/

#include "signal_name_t.h"

const signal_name_t SIGNAL_NAMES[] = {
    {SIGIO, "SIGIO"},
    {SIGBUS, "SIGBUS"},
    {SIGSYS, "SIGSYS"},
    {SIGURG, "SIGURG"},
    {SIGPWR, "SIGPWR"},
    {SIGFPE, "SIGFPE"},
    {SIGHUP, "SIGHUP"},
    {SIGILL, "SIGILL"},
    {SIGINT, "SIGINT"},
    {SIGABRT, "SIGABRT"},
    {SIGALRM, "SIGALRM"},
    {SIGCHLD, "SIGCHLD"},
    {SIGCONT, "SIGCONT"},
    {SIGTRAP, "SIGTRAP"},
    {SIGXCPU, "SIGXCPU"},
    {SIGXFSZ, "SIGXFSZ"},
    {SIGKILL, "SIGKILL"},
    {SIGPIPE, "SIGPIPE"},
    {SIGQUIT, "SIGQUIT"},
    {SIGSEGV, "SIGSEGV"},
    {SIGSTOP, "SIGSTOP"},
    {SIGTERM, "SIGTERM"},
    {SIGTSTP, "SIGTSTP"},
    {SIGTTIN, "SIGTTIN"},
    {SIGTTOU, "SIGTTOU"},
    {SIGUSR1, "SIGUSR1"},
    {SIGUSR2, "SIGUSR2"},
    {SIGPOLL, "SIGPOLL"},
    {SIGPROF, "SIGPROF"},
    {SIGWINCH, "SIGWINCH"},
    {SIGVTALRM, "SIGVTALRM"},
    {SIGSTKFLT, "SIGSTKFLT"},
    {-1, NULL},
};