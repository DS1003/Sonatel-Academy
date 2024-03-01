#include <stdio.h>

void inverse_tab (int [], int);

int main() {

    int tableau[] = {1, 2, 3, 4, 5};
    int n = 5;
    printf("Tableau initial: \n");
    for (int i = 0; i < n; i++) {
        printf("%d ", tableau[i]);
    }
    inversionTab(tableau, n);
    printf("\nTableau inverse: \n");
    for (int i = 0; i < n; i++) {
        printf("%d ", tableau[i]);
    }
    return 0;
}

void inversionTab(int tab[], int n)
{
    int i, j, temp;

    for (i = 0, j = n - 1; i < j; i++, j--)
    {
        temp = tab[i];
        tab[i] = tab[j];
        tab[j] = temp;
    }
}