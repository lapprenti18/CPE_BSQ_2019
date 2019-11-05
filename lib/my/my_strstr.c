/*
** EPITECH PROJECT, 2019
** my_strstr
** File description:
** ok
*/

#include <stdio.h>

char    *my_strstr(char *str, char const *to_find)
{
    int e = 0;
    int f = 0;
    int j;
    int r = 0;

    while (str[e] != to_find[f]){
        e = e + 1;
        if (str[e] == '\0')
            return (NULL);
    }
    while (str[e] == to_find[f]) {
        f = f + 1;
        r = r + 1;
        if (to_find[f] == '\0'){
            j = e;
            j = j - f;
            return (str + j);
        }
    }
    return (NULL);
}
