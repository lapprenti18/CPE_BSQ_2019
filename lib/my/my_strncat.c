/*
** EPITECH PROJECT, 2019
** str cat
** File description:
** ok
*/

char    *my_strncat(char *dest, char const *src)
{
    int i = 0;
    int a = 0;
    int nb = 1;

    if (nb <= 0) {
        return (0);
    }
    while (dest[i] != '\0') {
        i = i + 1;

    }
    while (nb > 0 && src[a] != '\0') {
        dest[i] = src[a];
        i = i + 1;
        a = a + 1;
        nb = nb - 1;
    }
    dest[i] = '\0';
    return (dest);
}
