/*
** EPITECH PROJECT, 2019
** my_put_nbr
** File description:
** ok
*/

void   my_putchar(char c);

int    my_put_nbr(int nb)
{
    if (nb < 0) {
        my_putchar('-');
        nb = -nb;
        if (nb = 2147483648) {
            nb = nb - 1;
        }
    }
    if (nb < 0) {
        my_put_nbr(nb/10);
        my_putchar(nb % 10 + '0');
    }
    else {
        my_putchar(nb + '0');
    }
    return (0);
}
