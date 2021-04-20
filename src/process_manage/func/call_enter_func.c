/*
** EPITECH PROJECT, 2021
** call_enter_func.c
** File description:
** call_enter_func
*/

#include "ftrace.h"

static char *find_name(unsigned long long addr, GElf_Shdr *shdr, Elf_Scn *scn, Elf *elf)
{
    size_t size = (shdr->sh_entsize) ? shdr->sh_size / shdr->sh_entsize : 0;
    Elf_Data *data = NULL;
    GElf_Sym sym = {0};
    char *name = NULL;

    data = elf_getdata(scn, NULL);
    for (size_t move = 0; move < size; ++move) {
        gelf_getsym(data, move, &sym);
        if (addr == sym.st_value) {
            name = elf_strptr(elf, shdr->sh_link, sym.st_name);
            break;
        }
    }
    return name;
}

static char *parse_elf(const char *path, unsigned long long addr)
{
    //printf("%s\n", path);
    GElf_Shdr shdr = {0};
    Elf_Scn *scn = NULL;
    char *name = NULL;
    Elf *elf = NULL;
    int fd = open(path, O_RDONLY);

    elf_version(EV_CURRENT);
    if (fd == -1)
        return NULL;
    elf = elf_begin(fd, ELF_C_READ, NULL);
    while ((scn = elf_nextscn(elf, scn)) != NULL) {
        gelf_getshdr(scn, &shdr);
        if (shdr.sh_type == SHT_SYMTAB) {
            break;
        }
    }
    name = find_name(addr, &shdr, scn, elf);
    elf_end(elf);
    close(fd);
    return name;
}

static char *get_func_name(int pid, unsigned long long regs_rip)
{
    data_link_t *tab = parse_maps(pid);
    unsigned long long addr = 0;
    char *sym_name = NULL;

    if (!tab)
        return NULL;
    for (size_t u = 0; tab[u].name; u++) {
        if (regs_rip >= (unsigned long long) tab[u].start && regs_rip <= (unsigned long long) tab[u].end) {
            //fprintf(stdout, "Hey I'm in! %s\n", tab[0].name);
            //addr = regs_rip - tab[u].start;
            addr = regs_rip - tab[0].start;
            sym_name = (tab[u].name[0]) ? parse_elf(tab[u].name, addr) : NULL;
            if (!sym_name)
                sym_name = parse_elf(tab[u].name, regs_rip);
            break;
        }
    }
    for (size_t i = 0; tab[i].name; i++)
        free(tab[i].name);
    free(tab);
    return sym_name;
}

bool call_enter_func(ftrace_t *data, struct user_regs_struct *regs, long rip)
{
    char *name = NULL;
    int ret = 0;

    ptrace(PTRACE_SINGLESTEP, data->pid, NULL, NULL);
    wait4(data->pid, &ret, 0, NULL);
    ptrace(PTRACE_GETREGS, data->pid, 0, regs);
    rip = ptrace(PTRACE_PEEKDATA, data->pid, regs->rip, NULL);
    name = get_func_name(data->pid, regs->rip);
    if (name)
        fprintf(stderr, "Entering function %s at 0x%llx\n", name, regs->rip);
    /*else
        fprintf(stderr, "Entering function %s at 0x%llx\n", "Unknown", regs->rip);*/
    return true;
}