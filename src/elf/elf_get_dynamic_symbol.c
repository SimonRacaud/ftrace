/*
** EPITECH PROJECT, 2021
** elf_get_dynamic_symbol.c
** File description:
** elf_get_dynamic_symbol
*/

#include "app.h"
#include <gelf.h>

static uint64_t get_pl_inf(Elf *elf, size_t idx_relaplt)
{
    size_t tmp = 0;
    Elf_Scn *section = NULL;
    GElf_Shdr section_header = {0};

    elf_getshdrstrndx(elf, &tmp);
    while ((section = elf_nextscn(elf, section)) != NULL) {
        gelf_getshdr(section, &section_header);
        if (section_header.sh_type == SHT_PROGBITS
        && strcmp(".plt", elf_strptr(elf, tmp, section_header.sh_name)) == 0)
            break;
    }
    return section_header.sh_addr + section_header.sh_entsize * idx_relaplt;
}

char *get_dynamic_name(Elf *elf,
size_t sh_link_dyntab, Elf_Data *data_dynsim, uint64_t addr)
{
    size_t tmp = 0;
    char *name = NULL;
    Elf_Scn *section = NULL;
    GElf_Shdr section_header = {0};
    GElf_Rela rela = {0};
    GElf_Sym sym = {0};
    Elf_Data *data_rela = NULL;

    elf_getshdrstrndx(elf, &tmp);
    while ((section = elf_nextscn(elf, section)) != NULL) {
        gelf_getshdr(section, &section_header);
        if (section_header.sh_type == SHT_RELA &&
        strcmp(".rela.plt", elf_strptr(elf, tmp, section_header.sh_name)) == 0)
            break;
    }
    data_rela = elf_getdata(section, NULL);
    for (size_t i = 0; i < section_header.sh_size / section_header.sh_entsize; i++) {
        gelf_getrela(data_rela, i, &rela);
        gelf_getsym(data_dynsim, GELF_R_SYM(rela.r_info), &sym);
        if (addr == get_pl_inf(elf, i)) {
            name = strdup(elf_strptr(elf, sh_link_dyntab, sym.st_name));
            break;
        }
    }
    return name;
}