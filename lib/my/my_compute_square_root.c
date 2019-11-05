/*
** EPITECH PROJECT, 2019
** my_compute_squar_root
** File description:
** ok
*/

int    my_compute_square_root(int nb)
{
    int i = 1;
    int e = 0;
    while (e * e != nb)
    {
        e = nb/i;
        i++;
        if (i > nb)
            return (0);
    }
    return (e);
}
