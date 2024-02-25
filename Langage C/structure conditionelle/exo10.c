#include <stdio.h>

int main() {
    int annee;
    
    printf("Entrez une annee : ");
    scanf("%d", &annee);

    if ((annee % 4 == 0 && annee % 100 != 0) || (annee % 400 == 0)) {
        printf("%d est une année bissextile.\n", annee);
    } else {
        printf("%d n'est pas une année bissextile.\n", annee);
    }
    return 0;
}
