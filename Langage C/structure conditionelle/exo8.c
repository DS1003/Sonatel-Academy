//Écrire un algorithme qui lit trois valeurs entières ( A, B et C) puis les affichent dans l’ordre croissant et décroissant.
//sans permutation et que deux printf pour l'affichage un pour l'ordre croissant et un pour le décroissant 


#include <stdio.h>

int main() {
    int A, B, C, min, max, mid;

    printf("Veuillez saisir trois valeurs entières : ");
    scanf("%d %d %d", &A, &B, &C);

    if (A <= B){
        if (A <= C){
            min = A;
            if (B <= C) {
                mid = B;
                max = C;
            }else{
                mid = C;
                max = B;
            }
        }
    } else if (B <= A) {
        if (B<=C) {
            min = B;
            if (A<=C){
                mid = A;
                max = C;
            }else {
                mid = C;
                max = A;
            }
        }
    } else {
        min = C;
        if (A <= B) {
            mid = A;
            max = B;
        } else {
            mid = B;
            max = A;
        }
    }
    printf("Ordre croissant : %d %d %d\n", min, mid, max);
    printf("Ordre décroissant : %d %d %d\n", max, mid, min);

    return 0;
}
