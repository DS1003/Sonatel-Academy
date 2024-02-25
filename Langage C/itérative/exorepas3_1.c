#include <stdio.h>

int main() {
    float note, moy, tot_note = 0, som_note = 0; 
    char rep = 'o';
    
    while (rep == 'o' || rep == 'O') {
        printf("Entrez une note : ");
        scanf("%f", &note);
        
        if (note < 0 || note > 20) {
            printf("\nNote invalide\n");
        } else {
            printf("Voulez-vous ressaisir une note ? O/N : ");
            scanf(" %c", &rep); // %c pour lire un caractère
            tot_note++;
            som_note += note;
        }
    }
    if (tot_note > 0) {
        moy = som_note / tot_note;
        printf("\nLa moyenne des notes est de %.2f \n", moy);
    } else {
        printf("\nAucune note valide saisie.\n");
    }
    
    return 0;
}
