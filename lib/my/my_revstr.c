/*
** EPITECH PROJECT, 2019
** my_revstr
** File description:
** ok
*/


int    my_strlen(char const *str)
{
    int i = 0;

    while (str[i] != '\0'){
        i = i + 1;
    }
    return (i);
}

void     my_swap(char *a, char *b)
{
    int c = *a;
    *a = *b;
    *b = c;
}

char     *my_revstr(char *str)
{
    int l = my_strlen(str)-1;
    int u = my_strlen(str);
    int d = 0;

    while (d < (u/2)) {
        my_swap(&str[l], &str[d]);
        l = l - 1;
        d = d + 1;
    }
    return (str);
}
