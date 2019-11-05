/*
** EPITECH PROJECT, 2019
** str cat
** File description:
** ok
*/

char    *my_strcat(char *dest, char const *src)
{
    int z = 0;
    int e = 0;

    while (dest[z] != '\0') {
        z = z + 1;

    }
    while (src[e] != '\0') {
        dest[z] = src[e];
        e = e + 1;
        z = z + 1;
    }
    dest[z] = '\0';
    return (dest);
}
