/*
** EPITECH PROJECT, 2021
** rmmod_t.h
** File description:
** rmmod_t
*/

#ifndef RMMOD_T_H
#define RMMOD_T_H

typedef struct rmmod_s
{
    unsigned char rm :3;
    unsigned char reg :3;
    unsigned char mod :2;
} __attribute__((packed)) rmmod_t;

#endif