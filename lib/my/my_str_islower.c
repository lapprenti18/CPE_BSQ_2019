/*
** EPITECH PROJECT, 2019
** lower
** File description:
** ok
*/

int    my_str_islower(char const *str)
{
    for (int a = 0; str[a] != '\0'; a++) {
        if (str[a] < 'a' || str[a] > 'z')
            return (0);
    }
    return (1);
}
