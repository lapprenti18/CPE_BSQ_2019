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

int fs_open_file(char const *filepath)
{
    int fd = open(filepath, O_RDONLY);

    if (fd <= 0) {
        my_putstr("FAILURE\n");
    } else
        my_putstr("SUCCESS\n");
    return (fd);
}

int main(int ac, char **av)
{
    int res = fs_open_file(av[1]);

    if (res = -1)
        return 84;
    return (res);
}