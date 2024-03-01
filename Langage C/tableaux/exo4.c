#include <stdio.h>



int main() {
    int N = 250;
    int tab1[N];
    int tab2[N];
    int resultat[N];

    // Remplissage aléatoire des tableaux
    for (int i = 0; i < N; i++)
    {
        tab1[i] = i;
        tab2[i] = 2 * i;
    }

    additionTab(tab1, tab2, resultat, N);

    // Affichage des 10 premières valeurs
    printf("Resultat (10 premiers elements) : \n");
    for (int i = 0; i < 10; i++)
    {
        printf("%d ", resultat[i]);
    }

    return 0;
}

void additionTab(int tab1[], int tab2[], int resultat[], int n) {
    for (int i = 0; i < n; i++)
    {
        resultat[i] = tab1[i] + tab2[i];
    }
}