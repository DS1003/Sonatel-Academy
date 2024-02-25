#include <stdio.h>
#include <math.h>

int main()
{
    const float pi = 3.1415926;
    float r, s, p;
    printf("Donner le rayon d'un  cercle : ");
    scanf("%f", &r);
    s = pi * pow(r, 2);
    p = 2 * pi * r;     
    printf("La surface du cercle est de %f cm2\n", s);
    printf("Le périmètre du  cercle est de %f cm\n", p);
    return 0;
}