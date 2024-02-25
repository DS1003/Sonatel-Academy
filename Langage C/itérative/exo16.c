#include <stdio.h>

int main() {
    char symbole;
    int hautf, haut_t, lracine;
    
    // Demander les informations à l'utilisateur
    printf("Symbole (choisissez parmi $, *, + ou 0) : ");
    scanf(" %c", &symbole);
    
    printf("Hauteur des feuilles : ");
    scanf("%d", &hautf);
    
    printf("Hauteur du tronc : ");
    scanf("%d", &haut_t);
    
    printf("Largeur des racines : ");
    scanf("%d", &lracine);
    
    // Dessiner le sapin
    int espace = hautf - 1;
    for (int i = 1; i <= hautf; i++) {
        for (int j = 1; j <= espace; j++)
            printf(" ");
        for (int j = 1; j <= 2 * i - 1; j++)
            printf("%c", symbole);
        printf("\n");
        espace--;
    }
    
    // Dessiner le tronc
    int espaces_tronc = (2 * hautf - lracine) / 2;
    for (int i = 0; i < haut_t; i++) {
        for (int j = 0; j < espaces_tronc; j++)
            printf(" ");
        printf("%c%c\n", symbole, symbole); // Une seule ligne verticale pour le tronc
    }
    
    return 0;
}
