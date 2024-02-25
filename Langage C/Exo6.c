#include <stdio.h>
#include <math.h>

int main()
{
    printf("Donnez la Longueur et la largeur d'un rectangle\n");
    float longueur, largeur, a, p, d;
    printf("Longueur : ");
    scanf("%f", &longueur);
    printf("Largeur : ");
    scanf("%f", &largeur);

    a = longueur * largeur;
    printf("\nL'aire du Rectangle est %.2f cm2", a);

    p = (longueur + largeur) * 2;
    printf("\nLe perimetre du Rectangle est %.2f cm", p);

    d = sqrt(pow(longueur, 2) + pow(largeur, 2));
    printf("\nLa diagonal du Rectangle est %.2f cm\n", d);

    return 0;
}