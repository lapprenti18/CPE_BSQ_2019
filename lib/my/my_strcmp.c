/*
** EPITECH PROJECT, 2019
** str cmp
** File description:
** ok
*/

int    my_strcmp(const char *s1, const char *s2)
{
    int r = 0;
    int e = 0;

    while (s1[e] == s2[e]) {
        e = e + 1;

        if (s1[e] == '\0' && s2[e] == '\0'){
            return (0);
        }
    }
    r = s1[e] - s2[e];
    return (r);
}