#include <stdio.h>

int main () {
    int i, pas, nbr;
    do
    {
        printf("Entrez un nombre entier (supérieur à 0 :\n)");
        scanf("%d", &nbr);
    } while (nbr<0);
    pas = 0;
    for ( i = 0; i <= (nbr/2); i++) {
        if (nbr%i == 0){
            pas++;
        }
    }

    if (pas == nbr){
        printf("Le nombre %d est parfait !!!", nbr);
    }  else {
        printf("Le nombre %d n'est pas parfait !!!", nbr);
    }
    return 0;   
}