#include <stdio.h>

int main(){
    float r1, r2, r3, resis_serie, resis_para;
    printf("Saisissez 3 Résistants\n");
    printf("R1: ");
    scanf("%f", &r1);
    printf("R2: ");
    scanf("%f", &r2);
    printf("R3: ");
    scanf("%f", &r3);
    resis_serie = r1 + r2 + r3;
    resis_para = (r1 * r2 * r3)/((r1*r2)+(r2*r3)+(r1*r3));
    printf("La résistances en série de R1 R2 et R3 est: %f\n", resis_serie);
    printf("La résistance en parallele de R1 R2 et R3 est: %f\n", resis_para);
    return 0;
}