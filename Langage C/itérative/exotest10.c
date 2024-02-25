//saisi nbr puis détermine et affiche le nombre de chiffre de ce nbr

#include <stdio.h>
#include <math.h>

int main (){
    long nbr;
    do {
        printf("Saisissez un nombre : \n");
        scanf("%ld", &nbr);
        if (nbr < 0) {
            printf("Le nombre doit être positif !");
        }
    }while (nbr<0);
    long nb_chiffres = 1;
    while(nbr != 0){
            nb_chiffres++;
            nbr = (nbr/10) - 1;
    }
    printf("Le nombre %ld contient %ld chiffre(s).\n", nbr, nb_chiffres);
    return 0;
}