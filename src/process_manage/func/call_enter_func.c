/*
** EPITECH PROJECT, 2021
** call_enter_func.c
** File description:
** call_enter_func
*/

#include "ftrace.h"

static ssize_t get_addr(char *str)
{
    ssize_t tmp = -1;
    size_t pos = 0;

    for (pos = 0; str[pos] && str[pos] != '-'; pos++);
    if (str[pos] == '-')
        str[pos] = '\0';
    else
        return -1;
    sscanf(str, "%lx", &tmp);
    return tmp;
}

static ssize_t get_offset_bin(int pid)
{
    ssize_t ret = -1;
    char *path = NULL;
    FILE *file = NULL;
    size_t size = 0;
    char *str = NULL;

    asprintf(&path, "/proc/%i/maps", pid);
    if (!path)
        return -1;
    file = fopen(path, "r");
    free(path);
    if (getline(&str, &size, file) == -1)
        return -1;
    if (str)
        ret = get_addr(str);
    fclose(file);
    return ret;
}

static char *get_func_name(ftrace_t *data, long unsigned int addr)
{
    Elf_Data *info = elf_getdata(data->bin.scn, NULL);
    GElf_Shdr shdr = {0};
    GElf_Sym sym = {0};
    size_t size = 0;

    gelf_getshdr(data->bin.scn, &shdr);
    size = shdr.sh_size / shdr.sh_entsize;
    for (size_t i = 0; i < size; i++) {
        gelf_getsym(info, i, &sym);
        if (addr == sym.st_value)
            return elf_strptr(data->bin.elf, shdr.sh_link, sym.st_name);
    }
    return NULL;
}

bool call_enter_func(ftrace_t *data, struct user_regs_struct *regs, long rip)
{
    ssize_t addr = 0;
    char *name = NULL;
    int ret = 0;

    ptrace(PTRACE_SINGLESTEP, data->pid, NULL, NULL);
    wait4(data->pid, &ret, 0, NULL);
    ptrace(PTRACE_GETREGS, data->pid, 0, regs);
    rip = ptrace(PTRACE_PEEKDATA, data->pid, regs->rip, NULL);
    addr = regs->rip - get_offset_bin(data->pid);
    if (addr == -1)
        return false;
    name = get_func_name(data, addr);
    if (name)
        fprintf(stderr, "Entering function %s at 0x%llx\n", name, regs->rip);
    else
        fprintf(stderr, "Entering function %s at 0x%llx\n", "Unknown", regs->rip);
    return true;
}