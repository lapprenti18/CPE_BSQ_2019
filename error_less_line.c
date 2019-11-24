/*
** EPITECH PROJECT, 2019
** CPE_BSQ_2019
** File description:
** error_less_line.c
*/

#include "include/my.h"
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>

int    error_less_line(char *map)
{
    int b = 0;

    for (int a = 0; map[a]; a += 1)
        if (map[a] == '\n')
            b += 1;
    return (b - 1);
}