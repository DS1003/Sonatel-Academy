#include <stdio.h>

//Prototype
void affichetab (int tab2[], int m);
void saisietab (int tab[],  int *n);
void trietab_asc (int tab[], int *t);
void trietab_desc (int tab[], int *t);
void transfertab10( int tab[], int *n, int tab2[], int *m);

//main
int main() {
    int taille=0, tab[taille];

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
            saisietab(tab, &taille);
            printf("---------------------- Tableau ------------------------\n");
            affichetab(tab, taille);
        }     
        if (choix == 2 &&  taille != 0) {
                char c2;
                do {
                    printf("a ---------- Trie par ordre croissant (asc)      \n");
                    printf("b ---------- Trie par ordre croissant (desc)     \n");
                    scanf("%s", &c2);
                    if ( c2 == 'a') {
                        printf("Trier le tableau en ordre ascendant\n");
                        trietab_asc(tab , &taille);
                        printf("\nApres trier : \n");
                        affichetab(tab, taille);
                    }
                    if ( c2 == 'b') {
                        printf("Trier le tableau en ordre ascendant\n");
                        trietab_desc(tab, &taille);
                        printf("\nApres trier : \n");
                        affichetab(tab, taille);
                    }
                    if (c2 != 'a' && c2 > 'b' ) {
                        printf("Ce menu n'existe pas...Veuillez entrer une option entre a et b");
                    }
                    
                }while (c2!='a' && c2 != 'b');
        }
        if (choix == 3 &&  taille != 0) {
            int tab2[taille]; // Déclarer un tableau pour stocker les valeurs transférées
            int taille2; // Variable pour stocker la taille du tableau transféré

            transfertab10(tab, &taille, tab2, &taille2); // Appel de la fonction transfertab10

            printf("------------------ Valeurs du tableau > 10 -----------------\n");
            affichetab(tab2, taille2); 
        }    
        if (choix == 4){
            printf("Merci & Aurevoir !!!\n");
        }  
        if (choix <= 0 || choix > 4){
            printf("Ce menu n'existe pas...Veuillez entrer une option entre 1 et 4\n");
        }  
        if (taille == 0) {
            printf("\n------- Veuillez remplire le tableau au préalable !!!\n");
        }    
    } while (choix !=4);
    

    return 0;
}

//Implémantation





void  affichetab (int tab2[], int m) {
    for (int i = 0; i < m; i++) {
        printf("%d  ", tab2[i]);
    }
}

void saisietab (int tab[],  int *n) {
    int a, cpt=0;
    char rep = 'O';
    printf("Remplissez le tableau\n");
    do {
        printf("Entrez une valeur: ");
        scanf("%d", &a);
        if ( a%2 == 0) {
            tab[cpt] = a;
            cpt++;// cpt = 0 + 1; cpt = 1
            do {
                printf("Voulez vous ressaisir un nombre ? O/N : ");
                scanf("%s",&rep);
                if (rep != 'O' && rep != 'o' && rep !='n' && rep != 'N') {
                    printf("Veuilleez saisir  O ou o pour Oui Et  N ou n pour Non \n");
                }
            }while (rep !='O' && rep != 'o' && rep  !='n' && rep != 'N');
        }
        if (a%2 != 0) {
            printf("veuillez  entrez un nombre pair !\n");
        }
    } while (rep == 'o' || rep == 'O' );

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