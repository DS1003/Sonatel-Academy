#include <stdio.h>
#include <math.h>

typedef struct {
    float abscisse_x;
    float ordonnée_y;
} Point;


Point saisie_point ();
void afficher_point (Point P);
float distance (Point A, Point B);

int  main() {
    Point a, b;
    printf("Point A :\n");
    a = saisie_point();
    afficher_point(a);
    
    printf("\nPoint B :\n");
    b = saisie_point(); 
    afficher_point(b);

    float dist = distance(a, b);
    printf("\n--------------\nLa distance entre le Point A et le Point B est:  %.1f \n",dist);

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

//Dist(A,B)=√(〖(Xb-Xa)〗^2+〖(Yb-Ya)〗^2 )
float racinecarre (float x) {return sqrt(x);}
float distance (Point A, Point B) {
    float Xdif=racinecarre(pow((B.abscisse_x - A.abscisse_x), 2));
    float Ydif=racinecarre(pow((B.ordonnée_y - A.ordonnée_y), 2));
    return (Xdif + Ydif);
}

void affiche_distance (Point A, Point B) {
    printf("Distance entre les points %f \n", distance(A,B));
}

void afficher_point (Point P) {
    printf("L'abscisse est %.1f et l'ordonnée est %.1f.\n", P.abscisse_x, P.ordonnée_y);
}
