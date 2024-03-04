#include <stdio.h>

//Prototypage
void saisietab (int tab[],  int *n);
void  affichetab (int tab2[], int m);

//main
int main () {
    int taille1 = 250, tab1[taille1];
    saisietab(tab1, &taille1);
    affichetab(tab1, taille1);


    return 0;
}

//implémentation
void saisietab (int tab[],  int *n) {
    int a, cpt=0;
    char rep = 'o';
    printf("Remplissez le tableau\n");
    do {
        printf("Entrez une valeur: ");
        scanf("%d", &a);
        if (a != 0) {
            tab[cpt] = a;
            cpt++;
        }
        if (a == 0 && cpt == 0) {
            printf("Veuillez remplir le tableau  d'au moins une case.\n");
        }
    } while (a != 0  && cpt!=0);
    *n = cpt;
}

void  affichetab (int tab2[], int m) {
    for (int i = 0; i < m; i++) {
        printf("%d  ", tab2[i]);
    }
    printf("\n");
}

void saisietri(int t[],int *n){
          int a,i=0,cpt=1,t;
          do{
            printf("Entrez une valeur: ");
             scanf("%d",&a);
           if (a!=0){
            t[i]=a;
            if(cpt==0){
              for(int k=0;k<*n;k++){
                for(int j=k+1;j<*n;j++){
                  if(t[k]>t[j]){
                    t=t[k];
                    t[k]=t[j];
                    t[j]=t;
                  }
                }
              }
            }  cpt=0; i++; *n=i+1;
           }
          }while(a!=0);
          *n=i;
   }