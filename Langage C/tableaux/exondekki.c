#include <stdio.h>

void saisir(int taille, int t[]);
void affiche(int t[], int n);



int main()
{
    int taille = 5, t[taille];
    saisir(taille, t);
    affiche(t, taille);
    return 0;
}



void saisir(int taille, int t[])
{
    char reponse = 'o';
    int i = 0, a;
    do
    {

        if (reponse == 'o')
        {
            printf("saisir un nombre :");
            scanf("%d", &a);
            if (a % 2 == 0)
            {
                t[i] = a;
                i++;
            }
        }
        if (i > 0 && i<taille) {
            printf("voulez vous continuer : ");
            scanf(" %c", &reponse);
        }

    } while (reponse == 'o' &&  i < taille);
    //*n = i;
}

void affiche(int t[], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("[%d]  ", t[i]);
    }
    printf("\n");
}