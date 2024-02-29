#include <stdio.h>

int isbissextile (int);
void isbissextile1 (int);
int saisiean (void);
void saisiean1 (void);

int main() { 
    saisiean1();
    return 0;
}

int isbissextile (int an) {
    if ((an % 4 == 0 && an % 100 != 0) || an % 400 ==  0) return 1;
    else return 0;
}

void isbissextile1 (int an){
    if (isbissextile(an)) 
        printf("\n%d est bissextile\n", an);
    else  
        printf("\n%d n'est pas bissextile\n" , an);     
}

int  saisiean () { 
    int a;
    do {
        printf("Saisir un an : ");
        scanf("%d", &a);
        if (a <= 0) printf("Erreur, l'annee doit etre superieure a zero.\n");
        else return a;
    } while (a <= 0);
}

void  saisiean1 () {  
    int anvalide;
    anvalide = saisiean();
    if (isbissextile(anvalide)) 
        printf("\n%d est bissextile\n", anvalide);
    else  
        printf("\n%d n'est pas bissextile\n" , anvalide); 
}