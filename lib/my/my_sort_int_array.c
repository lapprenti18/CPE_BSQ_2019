/*
** EPITECH PROJECT, 2019
** my_sort_array
** File description:
** ok
*/

void    my_switch(int *tab, int *tab2)
{
    int c = *tab;

    *tab = *tab2;
    *tab2 = c;
    return;
}
void    my_sort_int_array(int *tab, int size)
{
    int a = 0;
    int b = size;
    int c = size;

    while (size > 0){
        if (tab[a] <= tab[a+1])
            b++;
        else
            my_switch(&tab[a], &tab[a + 1]);
        size--;
        a++;
    }
    if (b != size) {
        my_sort_int_array(tab, c);
    }
    return;
}
