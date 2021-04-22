/*
** EPITECH PROJECT, 2021
** B-PSU-402-REN-4-1-ftrace-simon.racaud
** File description:
** 22/04/2021 main.c
*/

#include "app.h"

static const int ARGC_NEEDED = 2;

int main(int argc, char **argv)
{
    if (show_usages(argc, argv)) {
        return usage(EXIT_SUCCESS, argv[0]);
    } else if (argc != ARGC_NEEDED) {
        return usage(EXIT_FAILURE, argv[0]);
    }

    return EXIT_SUCCESS;
}