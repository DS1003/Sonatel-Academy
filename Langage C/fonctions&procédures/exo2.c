#include <stdio.h>

int isbissextile (int);
int nbr_jour (int, int);

int main() {
    int mois, an;
    printf("Entrez un mois et une année:\n");
    scanf("%d %d", &mois, &an);
    printf("Le nombre de jours pour %d/%d est: %d\n", mois, an, nbr_jour(mois, an));
    return 0;
}

int isbissextile (int an) {
    if ((an % 4 == 0 && an % 100 != 0) || an % 400 ==  0) return 1;
    else return 0;
}
//fonction nombre de jour avec switch case
int nbr_jour (int mois, int an) {
    switch (mois) {
        case 1: 3, 5, 7, 8, 10, 12; 
            return 31;
        case 2:
            if(isbissextile(an)) return 29;
            else  return 28;
        case 4: 6, 9,  11;
            return 30;
    }
}