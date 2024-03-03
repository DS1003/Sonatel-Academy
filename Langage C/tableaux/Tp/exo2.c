#include <stdio.h>

//Prototypage
void saisietab (int tab[],  int *n);
void  affichetab (int tab2[], int m);

//main
int main () {
    int taille1 = 250, tab1[taille1];
    saisietab(tab1, &taille1);
    affichetab(tab1, taille1);


    // Algo de trie
    int a, cpt=0, tab[cpt];
     printf("Entrez une valeur: ");
        scanf( "%d", &a);
        if (a != 0) {
            for  (int i = cpt ; i>=0 ;i--) {
                if (a  <= tab1[i]) {
                    tab[cpt] = tab1[i];
                    cpt++;
                    tab[cpt] = a;
                } else {
                   tab[cpt] = a;
                }
            }
            tab[cpt] = a;
            cpt++;
        }

    return 0;
}

//implémentation
void saisietab (int tab[],  int *n) {
    int a, cpt=0;
    char rep = 'o';
    printf("Remplissez le tableau\n");
    do {
        printf("Entrez une valeur: ");
        scanf( "%d", &a);
        if (a != 0) {
            if (cpt )
            cpt++;

        }
        if (a == 0 && cpt == 0) {
            printf("Veuillez remplir le tableau  d'au moins une case.\n");
        }
    } while (a != 0  && cpt!=0);
    *n = cpt;
}

void  affichetab (int tab2[], int m) {
    for (int i = 0; i < m; i++) {
        printf("%d  ", tab2[i]);
    }
    printf("\n");
}