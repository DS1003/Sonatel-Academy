#include <stdio.h>

int main()
{
    int j;
    printf(" Saisissez un chiffre compris entre 1 et 7  pour connaître le jour");
    scanf("%d", &j);
    if ((j < 1) && (j > 7))
    {
        printf("Saisissez un nombre correspondant au code donnée");
    }
    else
    {
        if (j == 1)
        {
            printf("Le chiffre saisi correspond à lundi \n");
        }
        else if (j == 2)
        {
            printf(" Le chiffre saisi correspond à Mardi \n");
        }
        else if (j == 3)
        {
            printf(" Le chiffre saisi correspond à Mercredi \n");
        }
        else if (j == 4)
        {
            printf(" Le chiffre saisi correspond à Jeudi\n");
        }
        else if (j == 5)
        {
            printf(" Le chiffre saisi correspond à Vendredi\n");
        }
        else if (j == 6)
        {
            printf(" Le chiffre saisi correspond à Samedi \n");
        }
        else
        {
            printf(" Le chiffre saisi correspond à Dimanche \n");
        }
    }
    return 0;
}
