#include <stdio.h>

int main(){
    int divisible, unit;
    printf("Saisissez un entier: \n");
    scanf("%d", &divisible);
    unit = divisible%10;
    if (unit == 0){
        printf("L'unité est égale à '0' donc la division est impossible");
        return 1;
    }else{
        if (divisible%unit == 0){
            printf("%d est divisible par son unité %d\n",divisible,unit);
        }else{
            printf("%d n'est pas divisible par son unité %d\n",divisible,unit);
        }
    }
    return 0;
}