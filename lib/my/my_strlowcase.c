/*
** EPITECH PROJECT, 2019
** low case
** File description:
** d
*/

char    *my_strlowcase(char *str)
{
    for (int e = 0; str[e] != '\0';e = e + 1){
        if (65 <= str[e] && str[e] <= 90){
            str[e] = str[e] + 32;
        }
    }
    return (str);
}
