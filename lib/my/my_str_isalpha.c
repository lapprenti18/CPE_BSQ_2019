/*
** EPITECH PROJECT, 2019
** is alpha
** File description:
** ok
*/

int    my_str_isalpha(char const *str)
{
    for (int a = 0; str[a] != '\0'; a++){
        if (str[a] < 'A' || str[a] > 'Z' && str[a] < 'a' || str[a] > 'z')
            return (0);
    }
    return (1);
}
