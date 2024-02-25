#include <stdio.h>

int main() {
    float note, moy, tot_note, som_note;
    char rep = 'o';
    for ( ; rep == 'o' ; ) {
        printf("Entrez une note : ");
        scanf("%f", &note);
        if (note < 0 || note  > 20) {
            printf("\nNote invalide\n");
        } else if (note >=0  && note <= 20){
            printf("Voulez-vous ressaisir une note ? O/N : ");  
            scanf("%s", &rep);
            tot_note++;
            som_note += note;
        }
    }
    moy =  som_note / tot_note;
    printf("\nLa moyenne des notes est de %.2f \n", moy);
    return 0;
}