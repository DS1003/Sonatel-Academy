#include <stdio.h>
#include <math.h>

int main(){
    char s;
    float taille, poids, PI, IMC;
    printf("Veuillez saisir votre sexe (M/F) : ");
    scanf("%c", &s);
    printf("Veuillez saisir votre taille : ");
    scanf("%f", &taille);
    printf("Veuillez saisir votre poids : ");
    scanf("%f", &poids);
    if (s == 'H' || s == 'h') {
        PI = (taille - 100) - (taille - 150) / 4;
    } else if (s == 'F' || s == 'f') {
        PI = (taille - 100) - (taille - 120) / 4;
    } else {
        printf("Le sexe que vous avez rentrez n'est pas valide \n");
        printf("Veuillez saisir votre sexe (M/F) : ");
        scanf("%c", &s);
        printf("Veuillez saisir votre taille : ");
        scanf("%f", &taille);
        printf("Veuillez saisir votre poids : ");
        scanf("%f", &poids);
        return 1;
    }
    taille = taille / 100;  
    IMC = poids / pow(taille,2);
    printf("Le Poids Idéal (PI) est : %.2f kg\n", PI);
    printf("Le IMC (Indice de Masse Corporelle) est : %.2f\n", IMC);
    if (IMC <= 27) {
        printf("Vous avez un poids normal.\n");
    } else if (IMC >= 32) {
        printf("Vous êtes considéré comme malade.\n");
    } else {
        printf("Vous êtes obèse.\n");
    }
    return 0;
}