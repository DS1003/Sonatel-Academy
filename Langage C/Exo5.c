#include <stdio.h>

int main (){
    float cfa, dollar, livre;
    printf("Entrez le montant en cfa que vous souhaitez convertire: ");
    scanf("%f", &cfa);
    dollar = cfa *  0.0016;
    livre = cfa * 0.0013;
    printf(" %.2f CFA equivaut a environ %.2f$ Dollars et a %.2f£ Livres Sterling\n" , cfa, dollar, livre);
    return 0 ;
}