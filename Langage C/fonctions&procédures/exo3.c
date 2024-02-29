#include <stdio.h>

int isdatevalide (int, int, int);
void isdatevalide1 (int, int, int);
int saisiedate (void);

int main (){

    return 0;
}

int isdatevalide (int j, int mois, int an) {
    if (an > 0 && mois > 0 && mois <= 12 && j > 0 && j <= nbr_jour(mois, an)) return 1;
    else return 0;
}

void isdatevalide1 (int j, int mois, int an){
    if (an > 0 && mois > 0 && mois <= 12 && j > 0 && j <= nbr_jour(mois, an))
        printf("La date %d/%d/%d est valide\n", j, mois, an);
    else  printf("Erreur: La date %d/%d/%d est invalide\n", j, mois, an);  
}

int saisirjour (void) {
    int jour;    
    printf("Saisir un jour : ");
    scanf("%d", &jour);
    return  jour;
}

int saisirmois (void) {
    int mois;    
    printf("Saisir un jour : ");
    scanf("%d", &mois);
    return  mois;
}

int saisiran (void) {
    int an;    
    printf("Saisir un jour : ");
    scanf("%d", &an);
    return  an;
}

int nbr_jour (int mois, int an) {
    if (mois == 4 || mois == 6 || mois == 9 || mois == 11) {
        return 30;
    } else if (mois ==  2) {
        if (isbissextile(an)){
            return 29;
         }else{
             return 28;
        }
    } else {
         return 31;
    }
}

int isbissextile (int an) {
    if ((an % 4 == 0 && an % 100 != 0) || an % 400 ==  0) return 1;
    else return 0;
}