#include <stdio.h>

int main () {
    int h, mn, s, h1, mn1, s1;
    char compar;
    printf("Entrez une heure (hh:mm:ss) : \n");
    scanf("%d %d %d", &h, &mn, &s);
    printf("Entrezla deuxième heure à comparer (hh:mm:ss) : \n");
    scanf("%d %d %d", &h1, &mn1, &s1);
    if (mn>59 || h>23 || s>59 || mn1>59 || h1>23 || s1>59 ){
        printf("Saisissez une heure valide sous le format 24h \n");
    } else {
        if (h>h1){
            compar='>';
        }else  {
            if (mn>mn1){
                compar='>';
            } else {
                if (s>s1){
                    compar='>';
                } else {
                    compar='=';
                }
            }
        }
        printf("\nL'heure %dh %dmn %ds %c %dh %dmn %ds !!! \n", h, mn, s, compar, h1, mn1, s1);
    }
    return 0;
}