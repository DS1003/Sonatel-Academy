#include <stdio.h>
#include "persolib.h"

int main() {
    int taille1=100, taille2;
    int tab1[taille1];
    saisietab(tab1, &taille1);

    taille2 = taille1; //taille2 est initialisée à la taille de tab1
    int tab2[taille2];
    transfertab(tab1, &taille1, tab2, &taille2);
    printf("----------------------------------\nTableau après transfert : \n");
    affichetab(tab2, &taille2);
    return 0;
}