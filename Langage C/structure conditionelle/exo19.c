#include <stdio.h>

int main (){
    int temps, h, mn, s;
    printf("Entrer une durée en seconde (s)");
    scanf("%d", &temps);
    h = temps/3600;
    mn = (temps%3600)/60;
    s = temps%60;
    printf("le temps convertie est équivaut à : %dh:%dmn:%ds\n", h, mn, s);
    return 0;
}