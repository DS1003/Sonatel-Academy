// saisir h mns s indique l'heure qu'il fera après une seconde
#include <stdio.h>

int main () {
    int h, mn, s;
    printf("Entrez une heure (hh:mm:ss) : \n");
    scanf("%d %d %d", &h, &mn, &s);
    if (mn>59 || h>23 || s>59 ){
        printf("Saisissez une heure valide sous le format 24h \n");
    } else {
        if (s!=59){
            s += 1;
            printf("L'heure après 1 seconde est : %dh %dmn %ds", h, mn, s);
        } else {
            s =0;
            if (mn != 59){
                mn += 1;
            } else {
                if (h!=23){
                    h += 1;
                    mn = 0;
                } else {
                    h = 0;
                }
            }
            printf("L'heure après 1 seconde est : %dh %dmn %ds\n", h, mn, s);
        }
    }
    
    return 0;
}