/*
** EPITECH PROJECT, 2019
** PSU_my_printf_2019
** File description:
** my_getnbr.c
*/

int my_getnbr(char *str)
{
int i;
int neg;
int n;

    neg = 1;
    i = 0;
    while (str[i] != '\0' && (str[i] == '+' || str[i] == '-')) {
        if (str[i] == '-')
            neg = neg * -1;
    i++;
    }
    n = 0;
    while (str[i] >= 48 && str[i] <= 57) {
        n = (n * 10) + str[i] - 48;
        i++;
    }
    return (n * neg);
}