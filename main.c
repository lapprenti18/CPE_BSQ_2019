/*
** EPITECH PROJECT, 2019
** CPE_BSQ_2019
** File description:
** main.c
*/

#include "include/my.h"
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>

int    height(char **av)
{
    char *buffer = malloc(sizeof(char) * 9);
    int fd = open(av[1], O_RDONLY);
    int x = 0;

    read(fd, buffer, 8);
    for (; buffer[x] <= '9' && buffer[x] >= '0'; x += 1);
    buffer[x + 1] = '\0';
    close(fd);
    return (my_getnbr(buffer));
}

int    widht(char **av)
{
    struct stat size_buff;
    char *buffer;
    int fd = open(av[1], O_RDONLY);
    int x = 0;
    int a = 0;

    stat(av[1], &size_buff);
    buffer = malloc(sizeof(char) * size_buff.st_size + 1);
    read(fd, buffer, size_buff.st_size + 1);
    for (; buffer[x] != '\n'; x += 1);
    x += 1;
    for (; buffer[x] == '.' || buffer[x] == 'o'; x += 1)
        a += 1;
    close(fd);
    free(buffer);
    return (a);
}

int    nb_word(char *str)
{
    int compteur = 0;

    for (int a = 0; str[a] != '\0'; a = a + 1) {
        if (str[a] == '\n')
            compteur++;
    }
    return (compteur);
}

int    is_alpha(char c)
{
    return (c == '.') || (c >= 'o') && (c != '\0');
}

char    **fill_tab(char **tab, char *str, int t)
{
    int i = 0;
    int e = 0;
    int x;

    for (int c = 0; c < t ; c++)
    {
        x = 0;
        for (; !is_alpha(str[e]); i += 1)
            e = e + 1;
        for (; is_alpha(str[e]); e += 1);
        tab[c] = malloc(sizeof(char) * (e - i + 1));
        for (; i < e; i += 1) {
            tab[c][x] = str[i];
            x = x + 1;
        }
        tab[c][x] = '\0';
    }
    return tab;
}

char    **my_str_to_word_array(char *str)
{
    char **tab;
    int t = nb_word(str);

    tab = malloc(sizeof(char *) * (t + 1));
    tab[t - 1] = NULL;
    if (str[0] == '\0')
        return (NULL);
    return (fill_tab(tab, str, t));
}

char    *fill(char **av)
{
    struct stat size_buff;
    int reslt = stat(av[1], &size_buff);
    char *buffer = malloc(sizeof(char) * size_buff.st_size + 1);
    int fd = open(av[1], O_RDONLY);
    int a = 0;

    for (int i = 0; i < size_buff.st_size + 1; i += 1) {
        buffer[i] = '\0';
    }
    read(fd, buffer, size_buff.st_size + 1);
    if (fd == -1)
        return "84";
    close(fd);
    return (buffer);
}

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

int    error_less_line(char *map)
{
    int b = 0;

    for (int a = 0; map[a]; a += 1)
        if (map[a] == '\n')
            b += 1;
    return (b - 1);
}

int    error_less_colone(char *map)
{
    int b = 0;
    int c = 0;
    int a = 0;

    for (; map[a] != '\n'; a += 1);
    a += 1;
    for (; map[a] != '\n'; a += 1)
        c += 1;
    a += 1;
    for (; map[a]; a += 1) {
        b = 0;
        for (; map[a] != '\n'; a += 1)
            b += 1;
        if (b != c)
            return 84;
    }
    return 0;
}

int    main_bsq(char **av)
{
    int nb_line = height(av);
    int nb_colone = widht(av);
    char *map = fill(av);
    char **tab = my_str_to_word_array(map);
    int a = 0;
    int b = 0;
    square_t square;
    int error_line = error_less_line(map);
    int error_colone = error_less_colone(map);

    if (error_line != nb_line || error_colone == 84)
        return (84);
    square.size = 0;
    for (int a = 0; tab[a] != NULL; a += 1)
        my_find_biggest(tab, &square, a);
    tab = my_print_square(square, tab);
    print_table(nb_colone, nb_line, tab);
    for (int z = 0; z < nb_line; z += 1)
        free(tab[z]);
    free(tab);
    free(map);
    return 0;
}

int    main(int ac, char **av)
{
    int fd = open(av[1], O_RDONLY);
    struct stat size_buff;
    int error;

    stat(av[1], &size_buff);
    if (fd == -1 || size_buff.st_size == 0 || ac != 2)
        return 84;
    error = main_bsq(av);
    if (error == 84)
        return 84;
    return (0);
}