#include <stdio.h>
#include <stdlib.h>

int saisie1 ();
int validation2 ();

int main () {
    int *n1, *n2;
    saisieglobal(&n1, &n2);
    printf("%d %d\n", *n1, *n2);
    return 0;
}

int saisie1 () {
    
    int nbr1;
    do {
        printf("Veuillez saisir un nombre entier positif : ");
        scanf("%d", &nbr1) ;
        if (nbr1 <= 0) {
            printf("Ce nombre est invalide, veuillez recommencer\n");
        } else if (nbr1 > 0 && nbr1 < 5){
            printf("Le nombre doit etre superieur ou égale à  5 pour être valide, veuillez recommencer\n") ;
        }
    } while (nbr1 < 5);
   
    return nbr1;
}

void saisieglobal (int *nbr1, int *nbr2) {
    char rep;
    *nbr1 = saisie1();
    printf("Voulez-vous ressaisir ? o/n : ");
    scanf("%s", &rep);
    while (getchar() !=  '\n');
    if(rep == 'o' || rep == 'O'){
      *nbr2 = validation2();
    }
}

int validation2 () {
    int nbr2=0;
    do {
        printf("Veuillez saisir un nombre entier positif : ");
        scanf("%d", &nbr2) ;
        if (nbr2 <= 0) {
            printf("Ce nombre est invalide, veuillez recommencer\n");
        } else if (nbr2 > 0 && nbr2 < 5){
            printf("Le nombre doit etre superieur ou égale à  5 pour être valide, veuillez recommencer\n") ;
        }
    } while (nbr2 < 5);
    return nbr2;
}