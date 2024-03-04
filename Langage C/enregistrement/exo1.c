#include <stdio.h>
#include <math.h>

typedef struct {
    float abscisse_x;
    float ordonnée_y;
} Point;


Point saisie_point ();
void afficher_point (Point P);

int  main() {
    Point a, b;
    printf("Point A :\n");
    a = saisie_point();
    afficher_point(a);
    
    printf("\nPoint B :\n");
    b = saisie_point(); 
    afficher_point(b);

    return 0;
}


Point saisie_point () {
    Point P;
  
    printf("Saisir l'abscisse : ");
    scanf("%f", &P.abscisse_x);
  
    printf("Saisir l'ordonnée : ");
    scanf("%f", &P.ordonnée_y);
  
    return P;
}
void afficher_point (Point P) {
    printf("L'abscisse est %.1f et l'ordonnée est %.1f.\n", P.abscisse_x, P.ordonnée_y);
}
