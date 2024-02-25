#include <stdio.h>

int main(){
    float r1, r2, r3, rs, rp;
    int choix;
    printf("Saisissez 3 résistances\n");
    scanf("%f %f %f", &r1, &r2, &r3);
    printf("Tapez 1 pour la résistence en série ou 2 pour celle en parallele \n");
    scanf("%d", &choix);
    if (choix == 1){
        rs = r1 + r2 + r3;
        printf("\nLa résistance en série est %f Ohms.\n", rs, r1, r2, r3);
    }else{
        rp = (r1 * r2 * r3) / ((r1*r2)+(r2*r3)+(r1*r3));
        printf("La résistance en parallele est %f Ohms.\n", rp);
    }
    return 0;
}           