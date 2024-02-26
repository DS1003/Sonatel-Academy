#include <stdio.h>

int isbissextile (int an) {
    if ((an % 4 == 0 && an % 100 != 0) || an % 400 ==  0) return 1;
    else return 0;
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

int main() {
    int mois, an;
    printf("Entrez un mois et une année:\n");
    scanf("%d %d", &mois, &an);
    printf("Le nombre de jours pour %d/%d est: %d\n", mois, an, nbr_jour(mois, an));
    return 0;
}