
/*
** EPITECH PROJECT, 2019
** get_nbr
** File description:
** getnbr
*/

int    my_getnbr(char const *str)
{
    int moin = 0;
    int a = 0;
    int b =  0;
    int c = 0;
    int d = 1;

    while (str[a] == '-' || str[a] == '+') {
        if (str[a] == '-')
            moin++;
        a++;
    }
    while (str[a] != '\0' && str[a] >= '0' && str[a] <= '9') {
        a++;
        b++;
    }
    a--;
    while (b > 0 && str[a] >= '0' && str[a] <= '9') {
        c = c + (str[a] - 48) * d;
        d = d * 10;
        b--;
        a--;
    }
    if (c < 0)
        return (0);
    if (moin %2 != 0)
        c = c * (-1);
    return (c);
}