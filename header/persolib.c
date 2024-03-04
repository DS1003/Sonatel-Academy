#include "persolib.h"
#include <stdio.h>
#include <sys/ioctl.h>
#include <stdlib.h>


//=========================================================================================================================

int somchiffre (int nbr) {
    int som = 0;
    while (nbr>0){
        som += nbr %10 ;
        nbr /= 10;
    }
    return som;
}

int comparaison (int a, int b) {
   if(a == b)
      return 1;
   else
      return 0;
}

int saisie (void){
    int n;
    do {
        printf ("Entrez un nombre  : ");
        scanf("%d", &n);
        if (n<0)printf("Entrez un nombre positif: ");
    } while (n<0);
    return n;
}

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

int  generer () {
    int n, test;
    do {
      n = rand() % 11;
      test=ispremier(n);
    }while(!test);
    return n;
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

//====================================== Dessin triangle/carre/rectangle ==================================================
void trianglerectangle (int hautf) {
    for (int i = 1; i <= hautf; i++) {
        printf("\t\t\t\t\t\t\t\t\t");
        for (int j = 1; j <= 2 * i - 1; j++)
            printf("*");
        printf("\n");
    }
}

int  saisie12() {
    
    int nbr1;
    do {
        printf("Veuillez saisir un nombre entier positif : ");
        scanf("%d", &nbr1) ;
        if (nbr1 <= 0) {
            printf("Ce nombre est invalide, veuillez recommencer\n");
        } else if (nbr1 > 0 && nbr1 < 5){
            printf("Le nombre doit etre superieur ou égale à  5 pour être valide, veuillez recommencer\n") ;
        }
    } while (nbr1 < 5);
   
    return nbr1;
}

void triangleisocele (int hautf) {
    int espace = hautf - 1;
    for (int i = 1; i <= hautf; i++) {
        printf("\t\t\t\t\t\t\t\t\t");
        for (int j = 1; j <= espace; j++)
            printf(" ");
        for (int j = 1; j <= 2 * i - 1; j++)
            printf("*");
        printf("\n");
        espace--;
    }
}

void carre (int cote) {
    for  (int i = 1; i <= cote; i++) {
        printf("\t\t\t\t\t\t\t\t\t");
        for (int j = 1; j <= cote; j++) {
            printf("* ");
        }
        printf("\n");
    }
}

void menuview () {
    char rep;
    int x, y, choix;
    x = saisie12();
    do {
        printf("Voulez-vous ressaisir ? o/n : ");
        scanf("%s", &rep);
        if(rep == 'o' || rep == 'O'){
            y = saisie12();
            if (x>y) {
                changerCouleurPolice(choisirCouleur());
                trianglerectangle(x);
            }
            if (x==y) {
                changerCouleurPolice(choisirCouleur());
                carre(x);
            }
            
        } else if (rep == 'n' || rep == 'N') {
            printf("1 ------------ Dessiner un Carré                  \n");
            printf("2 ------------ Dessiner un triangle               \n");
            printf("--------------------------------------------------\n");
            printf("\nChoisissez une option: ");
            scanf("%d", &choix);
            if (choix==1){
                carre(x);
            } else  if (choix==2) {
                printf("1 ------------ Triangle isocele                 \n");
                printf("2 ------------ Triangle rectangle               \n"); 
                printf("--------------------------------------------------\n");
                printf("\nChoisissez une option: ");
                scanf("%d", &choix);
                if (choix==1) {
                    changerCouleurPolice(choisirCouleur());
                    triangleisocele(x);
                } else {
                    changerCouleurPolice(choisirCouleur());
                    trianglerectangle(x);
                }
            }
        }
        printf("Répondez par o ou O pour OUI et  par n ou N pour NON.\n");
    } while (rep != 'o' && rep !='O' &&  rep!='N'  &&  rep!='n');
    printf("Merci aurevoir !!!\n");
}

void changerCouleurPolice(int couleur) {
    switch (couleur) {
    case 1:
        printf("\033[31m"); // Rouge
        break;
    case 2:
        printf("\033[32m"); // Vert
        break;
    case 3:
        printf("\033[34m"); // Bleu
        break;
    case 4:
        printf("\033[33m"); // Jaune
        break;
    case 5:
        printf("\033[35m"); // Magenta
        break;
    case 6:
        printf("\033[36m"); // Cyan
        break;
    default:
        printf("Couleur invalide.\n");
    }
}

int choisirCouleur() {
    int couleur;
    printf("Entrez la couleur de la police :  \n1 ----- Pour rouge \n2 ----- vert \n3 ----- Pour bleu \n4 ----- Pour jaune \n5 ----- magenta ) : ");
    scanf("%d", &couleur);
    return couleur;
}

//========================================= Tableau ========================================================================
void saisietab (int tab[],  int *n) {
    int a, cpt=0;
    printf("Remplissez le tableau\n");
    do {
        printf("Entrez une valeur: ");
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

void transfertab(int tab[], int *n, int tab2[], int *m) {
    *m = 0;
    for (int i = 0; i < *n; i++) {
        if (tab[i] % 2 == 0) {
            tab2[*m] = tab[i];
            (*m)++;
        }
    }
}

void  affichetab (int tab2[], int *m) {
    for (int i = 0; i < *m; i++) {
        printf("%d  ", tab2[i]);
    }
    printf("\n");
}