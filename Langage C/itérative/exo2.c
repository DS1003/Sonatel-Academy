#include <stdio.h>

int main() {
    int i, nbr, som;
    do {
        printf("Entrez  un nombre entier positif : \n");
        scanf("%d", &nbr);
    } while (nbr<0);
    for (i = 1; i < nbr; i++) {
        som += i;
    }
    printf("La somme des entiers jusqu'à %d est : %d\n", nbr, som);
    return 0;
}