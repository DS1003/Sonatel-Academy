#include <stdio.h>

int main (){
    int a, b, div_sous;
    do {
        printf("Entrez les nombres a et b (a doit être suppérieur ou égal à b) :\n"),
        scanf("%d %d", &a, &b);
    } while (b==0);
    while (a>=b) {
       a = a - b;
       div_sous++;
    }
    printf("La division de a par b par soustraction est : %d !!!\n", div_sous);
    return 0;
}