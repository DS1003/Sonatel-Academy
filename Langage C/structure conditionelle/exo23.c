#include <stdio.h>

int main(){
    
    int m1,j1,an1,jour,mois,an;

    printf("Saisissez la première date : \n");
    scanf("%d %d %d",&j1,&m1,&an1);
    printf("Saisissez la seconde date : \n");
    scanf("%d %d %d",&jour,&mois,&an);

     if(an>an1){
        printf("le date est plus récente est : %d/%d/%d\n",jour,mois,an);
     }else{
        if(an==an1){
            if(mois>m1){
                printf("le date est plus récente est : %d/%d/%d\n",jour,mois,an);
            }else {
                if(mois==m1){
                    if(jour>j1){
                        printf("la date la plus récente est : %d/%d/%d\n",jour,mois,an);
                    }else{
                       printf("la date la plus récente est : %d/%d/%d\n",j1,m1,an1); 
                    }
                }else if (m1>mois){
                       printf("la date la plus récente est : %d/%d/%d\n",j1,m1,an1);
                }
            }
        }else{
            if (an < an1){
                printf("la date la plus récente est : %d/%d/%d\n",j1,m1,an1);
            }
        }
     }
 return 0;
}