#include <stdio.h>

int main() {
    
    int ch = 0;
    do
    { 
        printf("\n********** Sous-Menu 4 ******************\n");
        printf("\n--------------- Choisissez une option ---------------\n\n1 ----- Afficher les deux plus grandes note d'une série de note (Arrêt par note négatif (ex: -1))\n2 ----- Afficher les deux plus grandes note d'une série de note (Arrêt par nombre de notes à saisir)\n3 ----- Afficher les deux plus grandes note d'une série de note (Arrêt par réponse (O/N ou o/n))\n4 ----- Retour\n\n--------------------------------Entrez votre choix :  ");
       
        scanf(" %d", &ch); 
        
        //------------------------------------------------ Choix invalide ----------------------------------------------------------------------
        if(ch<1  || ch>4) {
            printf("\nVotre entrée n'est pas valide, veuillez entrez une valeur comprise entre 1 et 4: \n");
        }
        //------------------------------------------------ Choix 1 -----------------------------------------------------------------------------
        if  (ch == 1) {
            float note, mil=0, max=0;
            int n, i;
            do {
                printf("\nEntrez la note: " );
                scanf("%f", &note);
                if ( note>20) {
                    printf("Erreur: La note doit être comprise entre 0 et 20.\n");
                }
                //Comparaison des deux plus grandes notes le dernier et l'avant dernier
                if (note > max && note <= 20){
                    mil= max;
                    max  = note;
                } else {
                        if (note >= mil && note <= 20 && note != max) {
                        mil = note;
                    }
                }
            } while (note>0);

            printf("\nLes deux plus grandes notes sont : %.1f et %.1f\n", mil, max);
        }
        //------------------------------------------------ Choix 2 -----------------------------------------------------------------------------
        if  (ch == 2) {
            float note, mil=0, max=0;
            int n, i;
            printf("Entrez un nombre de notes à saisir:  ");
            scanf("%d", &n);
            do {
                printf("Entrez un nombre de notes à saisir (le nombre doit être suppérieur à 0):  ");
                scanf("%d", &n);
                for(i = 1 ; i <= n ; i++) {
                    printf("\nEntrez la note %d : ", i);
                    scanf("%f", &note);
                    if (note < 0 || note>20) {
                        printf("Erreur: La note doit être comprise entre 0 et 20.\n");
                        i--;
                    }
                    //Comparaison des deux plus grandes notes le dernier et l'avant dernier
                    if (note > max && note <= 20){
                        mil = max;
                        max  = note;
                    } else {
                            if (note >= mil && note <= 20 && note != max) {
                            mil = note;
                        }
                    }
                }
            } while (n<0);
            printf("\nLes deux plus grandes notes sont : %.1f et %.1f\n", mil, max);
        }
        //------------------------------------------------ Choix 3 -----------------------------------------------------------------------------
        if  (ch == 3) {
            float note, max=0, mil=0;
            char rep = 'o';
            for ( ; rep == 'o' || rep == 'O'; ) {
                printf("Entrez une note : ");
                scanf("%f", &note);
                if (note < 0 || note  > 20) {
                    printf("\nNote invalide\n");
                } else if (note >=0  && note <= 20){
                    printf("Voulez-vous ressaisir une note ? O/N : ");  
                    scanf("%s", &rep);
                    //Comparaison des deux plus grandes notes le dernier et l'avant dernier
                    if (note > max && note <= 20){
                        mil = max;
                        max  = note;
                    } else {
                            if (note >= mil && note <= 20 && note != max) {
                            mil = note;
                        }
                    }
                }
            }
            printf("\nLes deux plus grandes notes sont : %.1f et %.1f\n", mil, max);
        }
        //------------------------------------------------ Choix 4 -----------------------------------------------------------------------------
        if  (ch == 4) {
            printf("\n--------------------------------------- Sortie Choix 4\n");
        }
    }while(ch != 4 && ch>=1);
    return 0;
}