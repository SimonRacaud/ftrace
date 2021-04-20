/*
** EPITECH PROJECT, 2019
** ftrace.h
** File description:
** ftrace
*/

#ifndef FTRACE_H
#define FTRACE_H

#include "libc.h"
#include "define.h"
#include "ftrace_t.h"
#include "link_func_t.h"
#include "ftrace_source.h"

/*
**
** FUNCTION
**
*/

data_link_t *parse_maps(int pid);
bool process_manage(ftrace_t *data);
void display_help(const char *binary);
bool init_struct(ftrace_t *data, int ac, char **av);
bool call_function(ftrace_t *data, long rip, struct user_regs_struct *regs);

/*
**
** DISPLAY FUNCTION
**
*/

bool ff_func(ftrace_t *data, struct user_regs_struct *regs, long rip);
bool exit_func(ftrace_t *data, struct user_regs_struct *regs, long rip);
bool call_syscall(ftrace_t *data, struct user_regs_struct *regs, long rip);
bool call_enter_func(ftrace_t *data, struct user_regs_struct *regs, long rip);

/*
**
** TOOLS
**
*/

char *pop_back(char **tab);
bool push_back(char ***tab, char *name);
char **my_str_to_array(const char *str);

#endif