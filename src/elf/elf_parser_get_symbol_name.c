/*
** EPITECH PROJECT, 2021
** B-PSU-402-REN-4-1-ftrace-simon.racaud
** File description:
** 27/04/2021 elf_parser_get_symbol_name.c
*/

#include "app.h"
#include <gelf.h>
#include <fcntl.h>
#include <unistd.h>

static size_t get_pl_inf(Elf *elf, size_t idx_relaplt)
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

static size_t get_nb_plt_sym(Elf *elf, size_t sh_link_dyntab, Elf_Data *data_dynsim)
{
    size_t tmp = 0;
    Elf_Scn *section = NULL;
    GElf_Shdr section_header = {0};
    GElf_Rela rela = {0};

    elf_getshdrstrndx(elf, &tmp);
    while ((section = elf_nextscn(elf, section)) != NULL) {
        gelf_getshdr(section, &section_header);
        if (section_header.sh_type == SHT_RELA && strcmp(".rela.plt", elf_strptr(elf, tmp, section_header.sh_name)) == 0)
            break;
    }
    Elf_Data *data_rela = elf_getdata(section, NULL);
    for (size_t i = 0; i < section_header.sh_size / section_header.sh_entsize; i++) {
        GElf_Sym sym;
        gelf_getrela(data_rela, i, &rela);
        gelf_getsym(data_dynsim, GELF_R_SYM(rela.r_info), &sym);
        printf("plt: %s = 0x%lx\n", elf_strptr(elf, sh_link_dyntab, sym.st_name), get_pl_inf(elf, i));
    }
    printf("size: %li\n", section_header.sh_size / section_header.sh_entsize);
    return section_header.sh_size / section_header.sh_entsize;
}

static char *elf_parser_find_name(
    uint64_t addr, GElf_Shdr *section_header, Elf_Scn *section, Elf *elf, bool stat)
{
    Elf_Data *data = NULL;
    GElf_Sym symbol = {0};
    size_t nb_symbol = 0;
    char *function_name = NULL;

    if (section_header->sh_entsize)
        nb_symbol = (section_header->sh_size / section_header->sh_entsize);
    data = elf_getdata(section, NULL);
    for (size_t idx = 0; idx < nb_symbol; idx++) {
        gelf_getsym(data, idx, &symbol);
        if (stat)
            printf("ici: %s at 0x%lx\n", elf_strptr(elf, section_header->sh_link, symbol.st_name), symbol.st_value);
        if (addr == symbol.st_value) {
            function_name =
                elf_strptr(elf, section_header->sh_link, symbol.st_name);
            break;
        }
    }
    if (!function_name)
        return NULL;
    return strdup(function_name);
}

char *elf_parser_get_symbol_name(char *elf_filepath, uint64_t addr)
{
    fflush(stdout);
    fflush(stderr);
    size_t sh_link_dyntab = 0;
    int fd = open(elf_filepath, O_RDONLY);
    Elf *elf = NULL;
    Elf_Scn *section = NULL;
    GElf_Shdr section_header = {0};
    char *function_name = NULL;

    if (fd == -1)
        return NULL;
    elf_version(EV_CURRENT);
    elf = elf_begin(fd, ELF_C_READ, NULL);
    while ((section = elf_nextscn(elf, section)) != NULL) {
        gelf_getshdr(section, &section_header);
        if (section_header.sh_type == SHT_SYMTAB)
            break;
    }
    function_name = elf_parser_find_name(addr, &section_header, section, elf, false);
    section = NULL;
    if (!function_name) {
        while ((section = elf_nextscn(elf, section)) != NULL) {
            gelf_getshdr(section, &section_header);
            if (section_header.sh_type == SHT_DYNSYM)
                break;
        }
        sh_link_dyntab = section_header.sh_link;
        Elf_Data *data = elf_getdata(section, NULL);
        function_name = elf_parser_find_name(addr - (16 * get_nb_plt_sym(elf, sh_link_dyntab, data)), &section_header, section, elf, false);
        if (!function_name)
            function_name = elf_parser_find_name(addr, &section_header, section, elf, false);
    }
    elf_end(elf);
    close(fd);
    return function_name;
}