#include <stdio.h>

void trianglerectangle (int);
void triangleisocele (int);
void carre (int);


int main() {
    char symbole;
    int hautf;
    // Demander les informations à l'utilisateur
    printf("Choisissez le symbole ($, *, + ou 0) : ");
    scanf(" %c", &symbole);
    
    printf("Hauteur des feuilles : ");
    scanf("%d", &hautf);
    carre(hautf, symbole);
    return 0;
}

void trianglerectangle (int hautf) {
    for (int i = 1; i <= hautf; i++) {
        for (int j = 1; j <= 2 * i - 1; j++)
            printf("*");
        printf("\n");
    }
}

void triangleisocele (int hautf) {
    int espace = hautf - 1;
    for (int i = 1; i <= hautf; i++) {
        for (int j = 1; j <= espace; j++)
            printf(" ");
        for (int j = 1; j <= 2 * i - 1; j++)
            printf("*");
        printf("\n");
        espace--;
    }
}

void carre (int cote) {
    for  (int i = 1; i <= cote; i++) {
        for (int j = 1; j <= cote; j++) {
            printf("* ");
        }
        printf("\n");
    }
}