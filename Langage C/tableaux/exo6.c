// Exercice 6
// Écrire un programme permettant de saisir, dans un tableau, des nombres compris entre -100 et +100 ensuite calcule et affiche le minimum, le maximum et la moyenne à partir du tableau.
#include <stdio.h>

int main()
{
    int taille;
    printf("Entrez la taille du tableau: ");
    scanf("%d", &taille);

    // Vérifier que la taille est positive
    if (taille <= 0)
    {
        printf("La taille du tableau doit être positive.\n");
        return 1;
    }

    int nombres[taille];
    int i;
    int min, max;
    double somme = 0.0;

    // Saisie des nombres
    for (i = 0; i < taille; i++)
    {
        printf("Entrez le nombre %d (entre -100 et 100): ", i + 1);
        scanf("%d", &nombres[i]);

        // Vérifier que le nombre est dans l'intervalle [-100, 100]
        if (nombres[i] < -100 || nombres[i] > 100)
        {
            printf("Le nombre doit être compris entre -100 et 100.\n");
            i--; // Demander à nouveau le même nombre
            continue;
        }

        // Initialiser min et max avec le premier nombre saisi
        if (i == 0)
        {
            min = max = nombres[i];
        }

        // Mise à jour de min et max
        if (nombres[i] < min)
        {
            min = nombres[i];
        }
        if (nombres[i] > max)
        {
            max = nombres[i];
        }

        // Calcul de la somme pour la moyenne
        somme += nombres[i];
    }

    // Calcul de la moyenne
    double moyenne = somme / taille;

    // Affichage des résultats
    printf("Minimum: %d\n", min);
    printf("Maximum: %d\n", max);
    printf("Moyenne: %.2f\n", moyenne);

    return 0;
}