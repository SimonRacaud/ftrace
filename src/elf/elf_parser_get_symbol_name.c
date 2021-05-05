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

static void move_to_section(Elf *elf,
Elf_Scn **section, GElf_Shdr *section_header, Elf64_Word type)
{
    while ((*section = elf_nextscn(elf, *section)) != NULL) {
        gelf_getshdr(*section, section_header);
        if (section_header->sh_type == type)
            break;
    }
}

static size_t get_nb_plt_sym(Elf *elf)
{
    size_t tmp = 0;
    Elf_Scn *section = NULL;
    GElf_Shdr section_header = {0};

    elf_getshdrstrndx(elf, &tmp);
    while ((section = elf_nextscn(elf, section)) != NULL) {
        gelf_getshdr(section, &section_header);
        if (section_header.sh_type == SHT_RELA &&
        strcmp(".rela.plt", elf_strptr(elf, tmp, section_header.sh_name)) == 0)
            break;
    }
    if (section_header.sh_entsize)
        return section_header.sh_size / section_header.sh_entsize;
    return 0;
}

static char *elf_parser_find_name(
    uint64_t addr, GElf_Shdr *section_header, Elf_Scn *section, Elf *elf)
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

static char *elf_parser_symbol(Elf *elf, uint64_t addr)
{
    GElf_Shdr section_header = {0};
    Elf_Data *data_dynsim = NULL;
    char *function_name = NULL;
    size_t sh_link_dyntab = 0;
    Elf_Scn *section = NULL;

    move_to_section(elf, &section, &section_header, SHT_SYMTAB);
    function_name = elf_parser_find_name(addr, &section_header, section, elf);
    section = NULL;
    if (!function_name) {
        move_to_section(elf, &section, &section_header, SHT_DYNSYM);
        sh_link_dyntab = section_header.sh_link;
        data_dynsim = elf_getdata(section, NULL);
        function_name = get_dynamic_name(elf,
        sh_link_dyntab, data_dynsim, addr - (16 * get_nb_plt_sym(elf)));
        if (!function_name)
            function_name = get_dynamic_name(elf,
            sh_link_dyntab, data_dynsim, addr);
    }
    return function_name;
}

char *elf_parser_get_symbol_name(char *elf_filepath, uint64_t addr)
{
    int fd = open(elf_filepath, O_RDONLY);
    Elf *elf = NULL;
    char *function_name = NULL;

    if (fd == -1)
        return NULL;
    elf_version(EV_CURRENT);
    elf = elf_begin(fd, ELF_C_READ, NULL);
    function_name = elf_parser_symbol(elf, addr);
    elf_end(elf);
    close(fd);
    return function_name;
}