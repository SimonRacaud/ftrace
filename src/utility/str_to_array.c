/*
** EPITECH PROJECT, 2021
** str_to_array.c
** File description:
** str_to_array
*/

#include <stdbool.h>
#include <stdlib.h>

static bool were_parth(const char c)
{
    if (c == ' ' || c == '\0' || c == '\n')
        return true;
    if (c <= 32)
        return true;
    return false;
}

static int cnt_word(const char *str)
{
    int cnt = 0;

    for (int i = 0; str[i] != '\0'; i++)
        if (!were_parth(str[i]) && were_parth(str[i + 1]))
            cnt++;
    return cnt;
}

static int *char_per_word(const char *str, int size)
{
    int cnt = 1;
    int move = 0;
    int *word = malloc(sizeof(int) * (size + 1));

    if (!word)
        return NULL;
    word[size] = -1;
    for (int i = 0; str[i] != '\0'; i++) {
        if (!were_parth(str[i]) && were_parth(str[i + 1])) {
            word[move] = cnt;
            cnt = 0;
            move++;
        }
        if (!were_parth(str[i]))
            cnt++;
    }
    return word;
}

static void tab_filler(const char *str, char **tab)
{
    int move = 0;
    int cnt = 0;

    for (int i = 0; str[i] != '\0'; i++) {
        if (!were_parth(str[i])) {
            tab[move][cnt] = str[i];
            tab[move][cnt + 1] = '\0';
            cnt++;
        }
        if (!were_parth(str[i]) && were_parth(str[i + 1])) {
            move++;
            cnt = 0;
        }
    }
}

char **my_str_to_array(const char *str)
{
    int size = cnt_word(str);
    char **tab = malloc(sizeof(char *) * (size + 1));
    int *word = char_per_word(str, size);

    if (!tab || !word)
        return NULL;
    tab[size] = NULL;
    for (int i = 0; i < size; i++) {
        tab[i] = malloc(sizeof(char) * (word[i] + 1));
        if (!tab[i])
            return NULL;
        tab[i][word[i]] = '\0';
    }
    tab_filler(str, tab);
    free(word);
    return tab;
}