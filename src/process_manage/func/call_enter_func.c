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
    //for (size_t i = 0; str || i == 0; i++) {
    if (getline(&str, &size, file) == -1)
        return -1;
    if (str) {
        ret = get_addr(str);
        //break;
    }
    //}
    fclose(file);
    return ret;
}

static long get_offset(long rip, int pid)
{
    //long ret_val = ptrace(PTRACE_PEEKDATA, pid, rip + 1, NULL);
    /*long ret_val = ptrace(PTRACE_PEEKDATA, pid, rip + 1);

    return (ret_val & 0xffffffff);*/
    long ret_val = ptrace(PTRACE_PEEKTEXT, pid, rip + 1);
    int offset = 0;

    if (ret_val == -1)
        return -1;
    offset = ret_val & 0xFFFFFFFF;
    return offset;
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
    int ret;
    struct rusage usage;

    ptrace(PTRACE_SINGLESTEP, data->pid, NULL, NULL);
    wait4(data->pid, &ret, 0, &usage);
    ptrace(PTRACE_GETREGS, data->pid, 0, regs);
    rip = ptrace(PTRACE_PEEKDATA, data->pid, regs->rip, NULL);

    unsigned long addr = regs->rip - get_offset_bin(data->pid);

    char *name = get_func_name(data, addr);
    if (name)
        fprintf(stderr, "Entering function %s at 0x%lx\n", name, regs->rip);
    else
        fprintf(stderr, "Entering function %s at 0x%lx\n", "Unknown", regs->rip);
    return true;
    /*
    //int second = ((unsigned) 0xFF00 & rip) >> 8;
    long offset_bin = get_offset_bin(data->pid);
    long offset = get_offset(regs->rip, data->pid);
    //long unsigned int addr = (regs->rip < off) ? regs->rip : regs->rip - off;
    //unsigned long addr = regs->rip + offset + 5;
    //unsigned long long int addr = regs->rip + offset - offset_bin + 5;
    unsigned long addr = regs->rip + offset + 5;

    char *name = get_func_name(data, addr);
    //name = get_func_name(data, 0x1160);

    //fprintf(stderr, "offset_bin=%#lx\taddr_to_find=%#lx\tcalculated addr=%#lx\t", offset_bin, offset, addr);
    if (name)
        fprintf(stderr, "Entering function %s at 0x%lx\n", name, addr);
    else
        fprintf(stderr, "Entering function %s at 0x%lx\n", "Unknown", addr);
    return true;*/
}