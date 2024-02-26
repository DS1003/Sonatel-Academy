#include <stdio.h>

int isdatevalide (int j, int mois, int an) {
    if (an > 0 && mois > 0 && mois <= 12 && j > 0 && j <= nbr_jour(mois, an)) return 1;
    else return 0;
}

int main (){
    int jour=0, mois=0, annee=0;    
    printf("Saisir une date au format JJ/MM/AAAA : ");
    scanf("%d/%d/%d", &jour,&mois,&annee);
    if (isdatevalide(jour,mois,annee)){
        printf("La date saisie est valide.\n");
    }else{
        printf("La date saisie est invalide.\n");
    }
    return 0;
}