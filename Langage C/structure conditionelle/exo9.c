#include <stdio.h>

int main() {
    int a, b, c, d, min, max, mil, moy;

    printf("Veuillez saisir 4 entiers: \n");
    scanf("%d %d %d %d", &a, &b, &c, &d);

    if (a<b){
        max = b;
        min = a;
    }else{
        min = b;
        max = a;
    }
    if (c<min){
        moy=min;
        min =c;
    } else if (c>max){
        moy = max;
        max=c;
    }
    if (d<max){
        moy=min;
        min=d;
    } else if (d>max) {
        mil=moy;
        moy=max;
        max=d;
    } else if (d>moy){
        mil = moy;
        moy = d;
    } else {
        mil = d;
    }
    printf("L'ordre croissant est : %d %d %d %d\n", min, mil, moy, max);
    printf("L'ordre croissant est : %d %d %d %d\n", max, moy, mil, min);
    return 0;
}