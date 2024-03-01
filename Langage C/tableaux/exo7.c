// EXERCICE 7 :
// Soit T un tableau qui contient n valeurs réelles triés dans l’ordre croissant. Ecrire une procédure
// qui prend comme paramètre le Tableau T, l’entier n (la taille de T) et un nombre réel x, et elle effectue l’insertion de x dans le tableau T, de telle manière que le tableau T reste trié.

#include <stdio.h>

// Prototype de la fonction d'insertion
void insererDansTableauTrie(double T[], int *n, double x);

int main()
{
    int n;
    double x;

    // Saisie de la taille du tableau
    printf("Entrez la taille du tableau: ");
    scanf("%d", &n);

    // Vérification que la taille est positive
    if (n <= 0)
    {
        printf("La taille du tableau doit être positive.\n");
        return 1;
    }

    // Création du tableau avec une taille supplémentaire pour l'insertion
    double T[n + 1];

    // Saisie des éléments du tableau déjà trié
    printf("Entrez les éléments du tableau trié en ordre croissant:\n");
    for (int i = 0; i < n; i++)
    {
        scanf("%lf", &T[i]);
    }

    // Saisie du nombre réel à insérer
    printf("Entrez le nombre réel à insérer: ");
    scanf("%lf", &x);

    // Insertion du nombre réel dans le tableau
    insererDansTableauTrie(T, &n, x);

    // Affichage du tableau après insertion
    printf("Tableau après insertion:\n");
    for (int i = 0; i < n; i++)
    {
        printf("%.2lf ", T[i]);
    }
    printf("\n");

    return 0;
}

// Fonction pour insérer x dans le tableau T trié
void insererDansTableauTrie(double T[], int *n, double x)
{
    int i = *n - 1;

    // Trouver la position pour l'insertion
    while (i >= 0 && T[i] > x)
    {
        T[i + 1] = T[i]; // Décaler les éléments vers la droite
        i--;
    }

    // Insérer x à la position trouvée
    T[i + 1] = x;

    // Augmenter la taille du tableau
    (*n)++;
}