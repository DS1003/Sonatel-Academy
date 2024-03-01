#include <stdio.h>

//prototypage
void transfertab (int *tab, int *n, int *tab2, int *m);
void saisietab (int *tab,  int *n);
void  affichetab (int *tab2, int *m);

//main
int main (){
   return 0;
}


//implémentation des fonctions 

void saisietab (int* tab,  int* n) {
    int a, cpt=0;
    printf("Remplissez le tableau\n");
    do {
        printf("Entrez une valeur\n");
        scanf( "%d", &a);
        if (a >= 0) {
            tab[cpt] = a;
            cpt++;
        } else {
            printf("Fin de saisie\n");
        }
    } while (a >= 0);
    *n = cpt;
}

void transfertab (int *tab, int *n, int *tab2, int *m) {
    *m=0;
    for  (int j = 0 ; j < *n ;j++) {
        if  (tab[j]%2 == 0) {
            tab2[m] = &tab[j];
            m++;     
        }
    }
}

void  affichetab (int *tab2, int *m) {
    for (int i = 0; i < *m; i++ ) {
        printf("%5d ", &tab2[i]);
    }
}