/*
** EPITECH PROJECT, 2019
** upper
** File description:
** ok
*/

int    my_str_isupper(char const *str)
{
    for (int a = 0; str[a] != '\0'; a++){
        if (str[a] < 'A' || str[a] > 'Z')
            return (0);
    }
    return (1);
}
