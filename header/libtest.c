#include <stdio.h>
#include "persolib_c"

int main () {
    int nbr = saisie();
    if (comparaison(nbr, somchiffre(nbr))) 
        printf("La somme des chiffres %d de ce nombre %d est égale à lui même\n", somchiffre(nbr), nbr);
    else
        printf("La somme des chiffres %d de ce nombre %d ne correspond pas à lui-même\n", somchiffre(nbr), nbr);
    return 0;
}