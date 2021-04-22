/*
** EPITECH PROJECT, 2021
** B-PSU-402-REN-4-1-ftrace-simon.racaud
** File description:
** 22/04/2021 stack_push.c
*/

#include "sstack.h"
#include <stdlib.h>
#include <string.h>

int stack_push(sstack_t **stack_ptr, char *value)
{
    sstack_t *node = malloc(sizeof(sstack_t));

    if (!node)
        return EXIT_FAILURE;
    node->str = strdup(value);
    node->next = NULL;
    if (!node->str)
        return EXIT_FAILURE;
    if (!(*stack_ptr)) {
        *stack_ptr = node;
    } else {
        node->next = (*stack_ptr);
        *stack_ptr = node;
    }
    return EXIT_SUCCESS;
}

char *stack_pop(sstack_t **stack_ptr)
{
    sstack_t *node;
    char *result;

    if ((*stack_ptr) == NULL) {
        return NULL;
    } else {
        node = (*stack_ptr);
        *stack_ptr = node->next;
        result = node->str;
        free(node);
        return result;
    }
}

void stack_destroy(sstack_t *stack)
{
    sstack_t *next;

    if (stack != NULL) {
        next = stack->next;
        if (stack->str)
            free(stack->str);
        free(stack);
        stack_destroy(next);
    }
}