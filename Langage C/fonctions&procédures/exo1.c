#include <stdio.h>

int isbissextile (int an) {
    if ((an % 4 == 0 && an % 100 != 0) || an % 400 ==  0) return 1;
    else return 0;
}


int main() { 
    int an;
    printf("Entrez une année: ");
    scanf("%d", &an);
    if (isbissextile(an)) 
        printf("\n%d est bissextile\n", an);
    else  
        printf("\n%d n'est pas bissextile\n" , an); 
    printf("Entrez un mois & une année: ");
    int mois;
    scanf("%d %d",&mois, &an);
    printf("Il y a %d jours dans ce mois.\n", nbr_jour(mois, an)); 
    int jour;
    printf("Entrez une date sous le format  JJ/MM/AAAA : ");
    scanf("%d/%d/%d",&jour, &mois, &an);
    if (isdatevalide(jour, mois, an))  
        printf("La date saisie est valide!\n");
    else
        printf("La date saisie est invalide!\n");    
    return 0;
}