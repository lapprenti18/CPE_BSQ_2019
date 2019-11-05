/*
** EPITECH PROJECT, 2019
** my_strncpy
** File description:
** ok
*/

char    *my_strncpy(char *dest, char const *src, int n){

    for (int i = 0; i != n; i++){
        dest[i] = src[i];
    }
    return (dest);
}
