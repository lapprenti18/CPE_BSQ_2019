/*
** EPITECH PROJECT, 2019
** capitalize
** File description:
** ok
*/

#include <stdio.h>

char    *my_strcapitalize(char *str)
{
    int i = 0;

    if (str[i] >= 'a' && str[i] <= 'z')
        str[i] = str[i] - 32;
    i++;
    while (str[i] != '\0') {
        if (str[i] <= 'Z' && str[i] >= 'A')
            str[i] = str[i] + 32;
        if (str[i] > 'z' || str[i] < 'a') {
            if (str[i+1] >= 'a' && str[i + 1] <= 122) {
                i++;
                str[i] = str[i] - 32;
            }
        }
        i++;
    }
    return (str);
}
