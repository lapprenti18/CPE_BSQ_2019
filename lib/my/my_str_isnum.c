/*
** EPITECH PROJECT, 2019
** is num
** File description:
** ok
*/

int    my_str_isnum(char const *str)
{
    for (int a = 0; str[a] != '\0'; a++) {
        if (str[a] < '0' || str[a] > '9')
            return (0);
    }
    return (1);
}
