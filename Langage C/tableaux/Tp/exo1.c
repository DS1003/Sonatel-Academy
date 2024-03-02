#include <stdio.h>

//Prototype
void  affichetab (int tab2[], int *m);
void saisietab (int tab[],  int *n);
char reparretsaisie ();

//main
int main() {
    int taille, tab[taille];
    saisietab(tab,  &taille);
    return 0;
}

//Implémantation
void  affichetab (int tab2[], int *m) {
    for (int i = 0; i < *m; i++) {
        printf("%d  ", tab2[i]);
    }
    printf("\n");
}

void saisietab (int tab[],  int *n) {
    int a, cpt=0;
    char rep = 'o';
    printf("Remplissez le tableau\n");
    do {
        printf("Entrez une valeur: ");
        scanf( "%d", &a);
        if (a >= 0 && a%2 == 0) {
            tab[cpt] = a;
            cpt++;
            do {
                printf("Voulez vous ressaisir un nombre ? O/N : ");
                scanf("%s",&rep);
                if (rep != 'O' && rep != 'o' && rep !='n' && rep != 'N') {
                    printf("Veuilleez saisir  O ou o pour Oui Et  N ou n pour Non \n");
                }
            }while (rep !='O' && rep != 'o' && rep  !='n' && rep != 'N');
        }
        if (a%2 != 0 || a<0) {
            printf("veuillez  entrez un nombre pair et positif\n");
        }
    } while (rep == 'o' || rep == 'O');
    *n = cpt;
}


