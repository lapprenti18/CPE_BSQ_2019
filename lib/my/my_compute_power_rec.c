/*
** EPITECH PROJECT, 2019
** my_computer_power_it
** File description:
** ok
*/

int    my_compute_power_rec(int nb, int p)
{
    int e = nb;

    if (p == 0) {
        return (1);
    }
    if (p < 0 || p > 32) {
        return (0);
    }
    e = nb * my_compute_power_rec (nb, p-1);
    return (e);
}
