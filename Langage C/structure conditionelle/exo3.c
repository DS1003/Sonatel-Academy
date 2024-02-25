#include <stdio.h>
int main(){
    int a,b;
    printf("Saisissez a et b: ");
    scanf("%d%d",&a,&b);
    if(a==0){
        if(b==0){
            printf("L'équation est toujours vrai \n");
            if(b!=0){
                printf("Impossible \n");
            }
        }
    }else {
        printf("le resultat est x = %d/%d",-b,a);
    }  
    return 0;
}