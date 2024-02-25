#include<stdio.h>

int main() {
    float t, f;
    printf("Donner la température en Celsius: ");
    scanf("%f", &t);
    f = (t * 1.8) + 32;
    printf("La température en Fahrenheit est : %.0f F\n", f);
    return 0;
}