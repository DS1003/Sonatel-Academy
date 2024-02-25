#include <stdio.h>

int main() {
    int montant, nbre_20, nbre_10, nbre_5, nbre_2, nbre_1;
    nbre_20 = 0;
    nbre_10 = 0;
    nbre_5 = 0;
    nbre_2 = 0;
    nbre_1 = 0;

    printf("Veuillez saisir votre montant en euros : ");
    scanf("%d", &montant);
if (montant < 1) {
printf("veullez saisir un montant valide");
}
else
{
    if (montant >= 20) {
        nbre_20 = montant / 20;
        montant = montant % 20;
    }

    if (montant >= 10) {
        nbre_10 = montant / 10;
        montant = montant % 10;
    }

    if (montant >= 5) {
        nbre_5 = montant / 5;
        montant = montant % 5;
    }

    if (montant >= 2) {
        nbre_2 = montant / 2;
        montant = montant % 2;
    }

    if (montant >= 1) {
        nbre_1 = montant / 1;
    }
    }
    printf("Vous pouvez avoir : %d billets de 20 euros\n", nbre_20);
    printf("Vous pouvez avoir : %d billets de 10 euros\n", nbre_10);
    printf("Vous pouvez avoir : %d billets de 5 euros\n", nbre_5);
    printf("Vous pouvez avoir : %d pièces de 2 euros\n", nbre_2);
    printf("Vous pouvez avoir : %d pièces de 1 euro\n", nbre_1);
    return 0;
}

