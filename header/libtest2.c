//génère un nombre  premier aléatoire puis l'utilisateur devra devinez ce nombre. Après 4  tentatives, le programme s'arrête et dis perdu ! S'il trouve on lui demande s'il veut continuer si oui on génère puis il devine sinon  arrêt du programme
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "persolib_c"

int ispremier (int);
void gameprime (int tofind);
int generer (void);


//----------------------------------- main -------------------------------------------------------------------
int main() {
    int primetofind;
    primetofind = generer();
    gameprime(primetofind);
    return 0;
}



//---------------------------------------- Fonctions & Procédure --------------------------------------------------------------
int ispremier (int nb) {
    int prime=0;
    for(int i = 1 ; i <= nb ; i++ ) {
        if(nb % i == 0) {
           prime++;
        }         
    }
    if(prime>2) return 0;
    else
       return 1;
}
    
void gameprime (int tofind){
    int n, cpt = 1;
    char choix;
    do {
        printf ("Entrez un nombre: ");
        scanf("%d", &n);
        if (n != tofind) {
            printf("Oups réessayer !\n");
            cpt++;
        }
        else {
            printf("Yeah ! Vous avez devinez !");
            printf("\nVoulez-vous Continuer ? o/n : ");
            char choix;
            scanf( "%s" , &choix);
            if (choix=='o'){
                tofind = generer();
                cpt = 1;
            } else if  (choix == 'n') {
                break;
            }
        }
        if  (cpt > 4) {
            printf("\nDommage... vous avez perdu !!!\n");
        }
    } while (cpt < 5);
}

int  generer (void) {
    int n, test;
    srand(time(NULL));
    do {
      n = rand() % 11;
      test=ispremier(n);
    }while(!test);
    return n;
}