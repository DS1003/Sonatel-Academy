#include <stdio.h>
#include <math.h>

int main(){
    float  d, x1, x2, y1, y2;
    printf("Entrez les coordonnées du point A (x1, y1): ");
    scanf("%f %f", &x1, &y1);
    printf("\nEntrez les coordonnées du point B (x2, y2): ");
    scanf("%f %f", &x2, &y2);
    d = sqrt( pow((x2-x1),2) + pow((y2-y1),2) );
    printf("\nLa distance entre le point A et le point B est : %.2f\n", d);
}