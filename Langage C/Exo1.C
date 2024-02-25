#include <stdio.h>

int main()
{
    int a, b;
    printf("Entrez deux entiers: \n");
    scanf("%d %d", &a, &b);
    int q;
    q = a/b;
    int r;
    r = a%b;
    printf("Le quotient de la division est: %d\n", q);
    printf("Le reste de la division est : %d\n", r);
    printf("Le ratio de la division est : %f\n", (float) q);
    return 0;
}