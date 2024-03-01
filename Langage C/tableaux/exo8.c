// EXERCICE 8 :
// Écrire un sous-programme qui permet de tester si deux nombres sont AMIS ou pas.
// Deux nombres M et N sont amis si la somme des diviseurs de N excepté 1 et lui-même est égale à M et la somme des diviseurs de M excepté 1 et lui-même est égale à N.
// Exemple : les nombres 48 et 75 sont deux nombres amis puisque :
// Les diviseurs de 48 sont : 2, 3, 4, 6, 8, 12, 16, 24 2 + 3 + 4 + 6 + 8 + 12 + 16 + 24 = 75  Les diviseurs de 75 sont : 3, 5, 15, 25 3 + 5 + 15 + 25 = 48.

#include <stdio.h>

// Prototype des fonctions
int sommeDiviseurs(int n);
int sontAmis(int m, int n);

int main()
{
    int m, n;

    // Saisie des deux nombres
    printf("Entrez le premier nombre: ");
    scanf("%d", &m);
    printf("Entrez le deuxième nombre: ");
    scanf("%d", &n);

    // Test si les nombres sont amis
    if (sontAmis(m, n))
    {
        printf("Les nombres %d et %d sont amis.\n", m, n);
    }
    else
    {
        printf("Les nombres %d et %d ne sont pas amis.\n", m, n);
    }

    return 0;
}

// Fonction pour calculer la somme des diviseurs propres d'un nombre
int sommeDiviseurs(int n)
{
    int somme = 0;
    for (int i = 2; i <= n / 2; i++)
    { // On commence à 2 car on exclut 1
        if (n % i == 0)
        {
            somme += i;
        }
    }
    return somme;
}

// Fonction pour tester si deux nombres sont amis
int sontAmis(int m, int n)
{
    return sommeDiviseurs(m) == n && sommeDiviseurs(n) == m;
}