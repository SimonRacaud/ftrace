/*
** EPITECH PROJECT, 2021
** str_to_array.c
** File description:
** str_to_array
*/

#include "ftrace.h"

static bool load_data(data_link_t *tab, char *line, size_t pos)
{
	char **parse = my_str_to_array(line);
	size_t size = 0;

	if (!parse)
		return false;
	for (size = 0; parse[size]; size++);
	sscanf(parse[0], "%lx-%lx", &tab[pos].start, &tab[pos].end);
	tab[pos].name = strdup((size == 6) ? parse[5] : "");
	for (size_t i = 0; parse[i]; i++)
		free(parse[i]);
	free(parse);
	tab[pos + 1].name = NULL;
	return (!tab[pos].name) ? false : true;
}

static bool read_maps(data_link_t **tab, FILE *file, size_t *alloc)
{
    size_t size = 0;
    char *str = NULL;

	for (size_t i = 0; str || !(*tab); i++) {
		if (getline(&str, &size, file) == -1)
			return true;
		*tab = realloc(*tab, sizeof(data_link_t) * (*alloc + 2));
		(*alloc)++;
		if (!(*tab))
			return false;
		if (!load_data(*tab, str, (*alloc) - 1))
			return false;
	}
	return true;
}

data_link_t *parse_maps(int pid)
{
	data_link_t *tab = NULL;
    char *path = NULL;
    FILE *file = NULL;
	size_t alloc = 0;

    asprintf(&path, "/proc/%i/maps", pid);
    if (!path)
        return NULL;
    file = fopen(path, "r");
    free(path);
    if (!file)
		return NULL;
	if (!read_maps(&tab, file, &alloc))
		return NULL;
    fclose(file);
    return tab;
}