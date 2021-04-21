/*
** EPITECH PROJECT, 2021
** constante.c
** File description:
** constante
*/

#include "ftrace.h"

const link_func_t REDIRECTION[] =
{
    {0xcd, 0x80, call_syscall},
    {0x0f, 0x05, call_syscall},
    {0xc3, 0, exit_func},
    {0xcb, 0, exit_func},
    {0xc2, 0, exit_func},
    {0xca, 0, exit_func},
    {0xe8, 0, ee_func},
    {0xff, 0, ff_func},
    {0x9a, 0, na_func},
    {0, 0, NULL}
};

const link_t SIGNAL_LINK[] = {
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