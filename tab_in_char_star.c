/*
** EPITECH PROJECT, 2019
** CPE_BSQ_2019
** File description:
** tab_in_char_*.c
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