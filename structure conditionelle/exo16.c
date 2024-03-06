#include <stdio.h>

int main(){
    int n, an, mois, j, an_type;
    printf("Saisissez une date jj/mm/aaaa : \n");
    scanf("%d %d %d", &j, &mois, &an);
    printf("Saisissez un chiffre (n) : \n");
    scanf("%d", &n);

    if (n<0){
        printf("La date saise est incorrecte !!!");
    } else {
        if (an%4 == 0 && an%100 != 0 || an%400 == 0){
            an_type = 366;
        }else {
            an_type = 365;
        }
        if (n > an_type) {
            an = an - n /  an_type;
            n=n%an_type;
        }
        j = j - n%31;
        mois = mois - n/31;
        if (j<=0) {
            j=j+31;
            mois--;
        }
        if (mois<=0){
            mois=mois+12;
            an--;
        }
        if (mois==1 || mois==3 || mois==5|| mois==7 || mois==8 || mois==10 || mois==12){
            if (j == 31){
                j = 31;
            } else {
                if (j == 31){
                    j = 30;
                }
                if (mois==2 && an_type==366){
                    j = 29;
                }else {
                    j = 28;
                }
            }
            printf ("La date avant %dj est : %d / %d / %d \n", n, j, mois, an);
        }   
    }
    return 0;
}