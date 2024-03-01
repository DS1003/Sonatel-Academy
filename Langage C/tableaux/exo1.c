#include <stdio.h>
#include <stdbool.h>

int consecutif_tab (int [], int);

int main() {
    int tab[5] = {1, 2, 7, 4, 5};
    if (consecutif_tab(tab, 5)) {
        printf("Le tableau contient des éléments consécutifs\n");
    } else {
        printf("Le tableau ne contient pas d'éléments consécutifs\n");
    }

    return 0;
}

int consecutif_tab(int tab[], int taille) {
    if (taille == 0)
        return true;

    int precedent = tab[0];

    for (int i = 1; i < taille; i++) {
        if (tab[i] != precedent + 1) {
            return 0;
        }
        precedent = tab[i];
    }
    return 1;
}