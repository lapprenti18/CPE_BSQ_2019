/*
** EPITECH PROJECT, 2019
** str to word array
** File description:
** 
*/

#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>

int    nb_word(char const *str)
{
    int compteur = 0;
    for (int a = 0; str[a] !='\0'; a = a + 1){
        while (str[a] >= '0' && str[a] <= '9' 
        || str[a] >= 'A' && str[a] <= 'Z' 
        || str[a] >= 'a' && str[a] <= 'z'){ 
            if (str[a + 1] < '0' 
            || str[a + 1] > '9' && str[a + 1] < 'A' 
            || str[a + 1] > 'Z' && str[a + 1] < 'a' 
            || str[a + 1] > 'z')
                compteur ++;
            a = a + 1;
        }
    }
    printf("compteur = ?%d",compteur);
    return(compteur);
}

int    is_alpha(char c)
{
    return (c >= '0') && (c <= '9')
        || (c >= 'A') && (c <= 'Z')
        || (c >= 'a') && (c <= 'z') && (c != '\0');
}

char    **my_str_to_word_array(char const *str)
{
    char **tab;
    int t = nb_word(str);
    int repere = 0;
    int i = 0;
    int e = 0;
    int x;

    tab = malloc(sizeof(char *) * t);
    tab[t] = NULL;
    printf("t =%d\n", t);
    if (str[e] == '\0')
        return(NULL);
    for (int c = 0; c < t ; c++)
    {
        x = 0;
        printf("c = %d\n", c);
        
        while (!is_alpha(str[e])) {
            e = e + 1;
            i = i + 1;
        }
        
        while (is_alpha(str[e])) {
            e = e + 1;
        }
        tab[c] = malloc(sizeof(char) * ((e + 1) - i));
        printf("e - i = %d %d\n",e, i);
        while (i < e) {
            tab[c][x] = str[i];
            x = x + 1;
            i = i + 1;
        }
        x = x +1;
        tab[c][x] = '$';
        printf("mot = %s\n", tab[c]);
    }
    return (tab);
}

int    main (void)
{
    char *str = "salut les boys";
    char **tab = my_str_to_word_array(str);
    return (0);
}
