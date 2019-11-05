/*
** EPITECH PROJECT, 2019
** printable
** File description:
** ok
*/

int    my_str_isprintable(char const *str)
{
    for (int a = 0; str[a] != '\0'; a++) {
        if (str[a] < ' ')
            return (0);
    }
    return (1);
}
