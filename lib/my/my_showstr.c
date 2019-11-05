/*
** EPITECH PROJECT, 2019
** showstr
** File description:
** lulu
*/

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

int    my_putchar (char c)
{
    write (1, &c, 1);
}

int    affichage (int b)
{
    if (b < 10)
        my_putchar(b);
    if (b == 10)
        my_putchar('a');
    if (b == 11)
        my_putchar('b');
    if (b == 12)
        my_putchar('c');
    if (b == 13)
        my_putchar('d');
    if (b == 14)
        my_putchar('e');
    if (b == 15)
        my_putchar('f');
    if (b == 16)
        my_putchar('g');
}

int    my_showstr(char const *str)
{
    int a;
    int b;

    for (int a = 0; str[a] != '\0'; a++) {
        if (str[a] < ' ' || str[a] == 127) {
            my_putchar('\\');
            a = str[a] / 16;
            if (a == 0)
                my_putchar('0');
            my_putchar(a);
            b = str[a] %16;
            affichage(b);
        }
        if (str[a] >= ' ')
        my_putchar(str[a]);
    }
    return (0);
}
