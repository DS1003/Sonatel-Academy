#include <stdio.h>

void fusion_tab (int [], int, int [], int);

int main() {
    int tab1[8] = {1, 3, 5, 7, 9, 0, 0, 0};
    int tab2[4] = {2, 4, 6, 8};
    fusionner(tab1, 5, tab2, 4);
    printf("Tableau fusionne : \n");
    for (int i = 0; i < 9; i++) {
        printf("%d ", tab1[i]);
    }
    return 0;
}

void fusion_tab (int tab1[], int n1, int tab2[], int n2) {
    int compt = 0;
    int i = 0, j = 0;
    while (i < n1 && j < n2) {
        if (tab1[i] > tab2[j]) {
            int t = tab1[compt];
            tab1[compt] = tab2[j];
            tab2[j] = t;
            compt++;
            j++;
        } else {
            compt++;
            i++;
        }
    }
}