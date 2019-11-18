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

int    Nb_line(char **av)
{
    char *buffer = malloc(sizeof(char) * 9);
    int fd = open(av[1], O_RDONLY);
    int x = 0;

    read(fd, buffer, 8);
    for (; buffer[x] <= '9' && buffer[x] >= '0'; x += 1);
    buffer[x + 1] = '\0';
    if (fd == -1)
        return 84;
    close(fd);
    return (my_getnbr(buffer));
}

int    Nb_colone(char **av)
{
    char *buffer = malloc(sizeof(char) * 10006);
    int fd = open(av[1], O_RDONLY);
    int x = 0;
    int a = 0;

    read(fd, buffer, 10006);
    for (; buffer[x] != '\n'; x += 1);
    x += 1;
    for (; buffer[x] == '.' || buffer[x] == 'o'; x += 1)
        a += 1;
    if (fd == -1)
        return 84;
    close(fd);
    free(buffer);
    return (a);
}

int    main(int ac, char **av)
{
    int nb_line = Nb_line(av);
    int nb_colone = Nb_colone(av);
    char **tab = malloc(sizeof(char) * (nb_line * nb_colone));

    return (0);
}