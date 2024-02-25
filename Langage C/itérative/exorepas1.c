#include <stdio.h>

int main() {
    float note, max=0, min=20;
    printf("Entrer la/les note(s) :\n");
    do {
        scanf("%f", &note);
        if (note < min && note>=0) {
            min = note;
        } 
        if (note > max && note<=20){
            max = note;
        }
    } while (note>0);
    
    if (min == max) {
        printf("Les notes sont tous identiques !!!\n");
    } else if (min < max){
        printf("Le Minimum est: %.1f\tLe Maximum est: %.1f\n", min, max);
    }
    printf("Merci !!!");
    return 0;
}