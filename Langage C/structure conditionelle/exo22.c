#include <stdio.h>

int main()
{
    int numero;
    print("saisir le numéro de saison : ");
    scanf("%d", numero);
    if (numero == 12 || numero == 1 || numero || numero == 2) {
        printf("saison hiver: ");
    }
    if (numero == 3 || numero == 4 || numero || numero == 5) {
        printf("saison printemps : ");
    }
    if (numero == 6 || numero == 7 || numero || numero == 8) {
        printf("saison été : ");
    }
    if (numero == 9 || numero == 10 || numero || numero == 11) {
        printf("saison automne : ");
    }
}