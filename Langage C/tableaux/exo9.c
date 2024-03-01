// EXERCICE 9 :
// Écrire un sous-programme qui détermine la position et le nombre de valeur de la sous-suite de valeurs la plus longue.

#include <stdio.h>

// Prototype de la fonction
void trouverSousSuiteLaPlusLongue(int arr[], int n, int *position, int *longueur);

int main()
{
    int n;

    // Saisie de la taille du tableau
    printf("Entrez la taille du tableau: ");
    scanf("%d", &n);

    // Vérification que la taille est positive
    if (n <= 0)
    {
        printf("La taille du tableau doit être positive.\n");
        return 1;
    }

    int arr[n];

    // Saisie des éléments du tableau
    printf("Entrez les éléments du tableau:\n");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    int position, longueur;
    trouverSousSuiteLaPlusLongue(arr, n, &position, &longueur);

    // Affichage de la position et de la longueur de la sous-suite la plus longue
    printf("La sous-suite de valeurs la plus longue commence à la position %d et a une longueur de %d.\n", position, longueur);

    return 0;
}

// Fonction pour trouver la sous-suite consécutive de valeurs identiques la plus longue
void trouverSousSuiteLaPlusLongue(int arr[], int n, int *position, int *longueur)
{
    int currentLength = 1;
    int maxLength = 1;
    int startPos = 0;

    *position = 0; // Position de début de la sous-suite la plus longue
    *longueur = 1; // Longueur de la sous-suite la plus longue

    for (int i = 1; i < n; i++)
    {
        if (arr[i] == arr[i - 1])
        {
            // Si la valeur actuelle est identique à la précédente, incrémenter la longueur actuelle
            currentLength++;
        }
        else
        {
            // Sinon, réinitialiser la longueur actuelle
            currentLength = 1;
            startPos = i;
        }

        // Si la longueur actuelle est plus grande que la longueur maximale enregistrée, mettre à jour
        if (currentLength > maxLength)
        {
            maxLength = currentLength;
            *position = startPos;
            *longueur = maxLength;
        }
    }
}