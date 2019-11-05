/*
** EPITECH PROJECT, 2019
** strupcase
** File description:
** ok
*/

char     *my_strupcase(char *str)
{
    for (int e = 0; str[e] != '\0';e = e + 1){
        if (97 <= str[e] && str[e] <= 122) {
            str[e] = str[e] - 32;
        }
    }
    return (str);
}
