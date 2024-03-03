#include <stdio.h>

//Prototype
void  affichetab (int tab2[], int m);
void saisietab (int tab[],  int *n);
void trietab_asc (int tab[], int *t);
void trietab_desc (int tab[], int *t);

//main
int main() {
    int taille = 1000, tab[taille];
    saisietab(tab,  &taille);
    printf("Trier le tableau en ordre ascendant\n");
    affichetab(tab,  taille);
    trietab_desc(tab, &taille);
    printf("\nApres trier : \n");
    affichetab(tab, taille);

    int choix;
    do {
        printf("\n=======================================================\n");
        printf("\n                       Menu                            \n");
        printf("1 ---------- Saisir un tableau                           \n");
        printf("2 ---------- Trier le tableau                            \n");
        printf("3 ---------- Transfert des valeurs du tableau > 10       \n");
        printf("4 ---------- Quitter                                     \n");
        scanf(" %d",&choix);
        if (choix == 1) {

        }     
        if (choix )       
    } while (choix !=4);
    

    return 0;
}

//Implémantation
void  affichetab (int tab2[], int m) {
    for (int i = 0; i < m; i++) {
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


void trietab_asc(int tab[], int *t) {
    int i,j,c;
    for(i = 0; i < *t-1 ; i++) {
        for(j = i + 1; j < *t; j++){
            if ( tab[i] > tab[j] ) {
                c = tab[i];
                tab[i] = tab[j];
                tab[j] = c;
            }
        }
    }
}

void trietab_desc(int tab[], int *t) {
    int i,j,c;
    for(i = 0; i < *t-1 ; i++) {
        for(j = i + 1; j < *t; j++){
            if ( tab[i] < tab[j] ) {
                c = tab[i];
                tab[i] = tab[j];
                tab[j] = c;
            }
        }
    }
}

void transfertab10( int tab[], int *n, int tab2[], int *m) {
    *m = 0;
    for (int i = 0; i < *n; i++) {
        if (tab[i] > 10) {
            tab2[*m] = tab[i];
            (*m)++;
        }
    }
}