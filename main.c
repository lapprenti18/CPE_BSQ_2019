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

char **my_str_to_word_array(char *str);

int error_less_line(char *map);

int height(char **av);

int widht(char **av);

char    *fill(char **av);

void my_find_biggest(char **tab, square_t *square, int cursor);

char **my_print_square(square_t square, char **tab);

void print_table(int nb_colone, int nb_line, char **tab);

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

    if (error_line != nb_line )
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
