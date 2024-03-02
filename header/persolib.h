#ifndef PERSOLIB_INCLUDED
#define PERSOLIB_INCLUDED

int somchiffre (int);
int saisie  (void); 
int comparaison(int, int);
int ispremier (int);
void gameprime (int tofind);
int generer (void);
void trianglerectangle (int);
void rectangle2 (int, int);
void triangleisocele (int);
void carre (int);
int saisie12();
void saisieglobal();
void menuview();
void changerCouleurPolice(int);
int choisirCouleur();
//Tableau 
void transfertab (int tab[], int *n, int tab2[], int *m);
void saisietab (int tab[],  int *n);
void  affichetab (int tab2[], int *m);

#endif
