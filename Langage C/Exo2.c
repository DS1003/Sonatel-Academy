#include <stdio.h>

int main()
{
    float dm;

    printf("Entrer une mesure en décimètres (dm) : ");
    scanf("%f", &dm);

    float m = dm / 10.0;
    float mm = dm * 100.0;
    float cm = dm * 10.0;
    float hm = dm / 100.0;

    printf("%f dm équivaut à :\n", dm);
    printf("%f m\n", m);
    printf("%f mm\n", mm);
    printf("%f cm\n", cm);
    printf("%f hm\n", hm);

    return 0;
}
