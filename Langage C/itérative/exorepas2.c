#include <stdio.h>

int main() {
    float note, mil=20, min=20;
    int n, i;
    printf("Entrez un nombre de notes à saisir:  ");
    scanf("%d", &n);
    
    for(i = 1 ; i <= n ; i++) {
        printf("\nEntrez la note %d : ", i);
        scanf("%f", &note);
        if (note < 0 || note>20) {
            printf("Erreur: La note doit être comprise entre 0 et 20.\n");
            i--;
        }
        //Comparaison des deux plus petites notes le dernier et l'avant dernier
        if (note < min && note >= 0){
            mil= min;
            min  = note;
        } else {
            if (note <= mil && note >= 0) {
                mil = note;
            }
        }
    }

    printf("\nLes deux plus petites notes sont : %.1f et %.1f\n", mil, min);
    
    return 0;
} 