/*
** EPITECH PROJECT, 2019
** CPE_BSQ_2019
** File description:
** find_square.c
*/

#include "include/my.h"
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>

int    size_upgrade(char **tab, int cursor, int repere, int size)
{
    while (size > 0) {
        if (tab[cursor][repere - size] == '.'
        && tab[cursor - size][repere] == '.')
            size -= 1;
        else
            return 1;
    }
    return 0;
}

int    my_calc_size(char **tab, int cursor, int repere)
{
    int size = 1;
    int test = 0;

    while (tab[cursor]) {
        test = 1;
        if (tab[cursor][repere] == '.')
            test = size_upgrade(tab, cursor, repere, size);
        if (test == 0) {
            cursor += 1;
            repere += 1;
            size += 1;
        } else
            return size;
    }
    return size;
}

void    my_find_biggest(char **tab, square_t *square, int cursor)
{
    int repere = 0;
    int size = 0;

    for (int repere = 0; tab[cursor][repere]; repere += 1) {
        size = 0;
        if (tab[cursor][repere] == '.' && tab[cursor + 1])
            size = my_calc_size(tab, cursor + 1, repere + 1);
        if (size > square->size) {
            square->size = size;
            square->x = repere;
            square->y = cursor;
        }
    }
}

char    **my_print_square(square_t square, char **tab)
{
    int y = square.y;
    int x = square.x;

    while (y != square.y + square.size) {
        while (x != square.x + square.size) {
            tab[y][x] = 'x';
            x += 1;
        }
    y += 1;
    x = square.x;
    }
    return (tab);
}

void    print_table(int nb_colone, int nb_line, char **tab)
{
        for (int z = 0; z < nb_line; z += 1) {
        write(1, tab[z], nb_colone);
        write(1, "\n", 1);
    }
}