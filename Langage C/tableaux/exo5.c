// EXERCICE 5 :
// Écrire un sous-programme qui, à partir de deux tableaux de même taille respective N1 = 150 et N2 = 30, retourne le résultat SOM. Pour calculer SOM, il faut multiplier chaque élément du premier tableau par chaque élément du deuxième tableau, et additionner le tout.
#include <stdio.h>

int calculSom(int tab1[], int tab2[], int n1, int n2)
{

    int som = 0;

    for (int i = 0; i < n1; i++)
    {
        for (int j = 0; j < n2; j++)
        {
            som += tab1[i] * tab2[j];
        }
    }

    return som;
}

int main()
{

    int n1 = 150, n2 = 30;
    int tab1[n1], tab2[n2];

    // Initialisation aléatoire des tableaux

    for (int i = 0; i < n1; i++)
    {
        tab1[i] = i;
    }

    for (int i = 0; i < n2; i++)
    {
        tab2[i] = i * 2;
    }

    int resultat = calculSom(tab1, tab2, n1, n2);

    printf("Som = %d", resultat);

    return 0;
}