/*
** EPITECH PROJECT, 2021
** init_struct.c
** File description:
** init_struct
*/

#include "ftrace.h"

static char *get_path_from_pid(int pid)
{
    char *path = NULL;

    asprintf(&path, "/proc/%i/exe", pid);
    if (!path)
        return NULL;
    if (access(path, F_OK) != 0)
        return NULL;
    return path;
}

static void set_symtab(binary_t *bin)
{
    GElf_Shdr shdr = {0};

    while ((bin->scn = elf_nextscn(bin->elf, bin->scn)) != NULL) {
        gelf_getshdr(bin->scn, &shdr);
        if (shdr.sh_type == SHT_SYMTAB) {
            bin->have_symtab = true;
            break;
        }
    }
    bin->have_symtab = false;
}

bool init_binary(binary_t *bin, int pid)
{
    char *path = get_path_from_pid(pid);

    if (!path)
        return false;
    printf("%s\n", path);
    //bin->fd = open(path, O_RDONLY);
    bin->fd = open("./tata", O_RDONLY);
    free(path);
    if (bin->fd == -1)
        return false;
    if (elf_version(EV_CURRENT) == EV_NONE)
        return false;
    bin->elf = elf_begin(bin->fd, ELF_C_READ, NULL);
    if (!bin->elf)
        return false;
    set_symtab(bin);
    return true;
}

void destroy_binary(binary_t *bin)
{
    elf_end(bin->elf);
    close(bin->fd);
}