/*
** EPITECH PROJECT, 2019
** strc mp
** File description:
** ok
*/

int    my_strncmp(const char *s1, const char *s2, int n)
{
    int r = 0;
    int e = 0;

    while (s1[e] == s2[e]) {
        e = e + 1;

        if (e == n) {
            r = s1[e]- s2[e];
        }
        if (s1[e] == '\0' && s2[e] == '\0'){
            return (0);
        }
    }
    r = s1[e] - s2[e];
    return (r);
}
