#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    int jour;
    int mois;
    int an;
} Date;

// Structure représentant un animal
typedef struct {
    char categorie[20];
    int poids;
     date_naissance[11]; // Format : jj/mm/aaaa
} Animal;



int main() {
    int N1 = 450;
    int N2 = 300;

    // Déclarations et initialisations des tableaux d'animaux
    Animal tableau1[N1];
    Animal tableau2[N2];

    // Remplissage des tableaux avec des données (à adapter selon vos besoins)

    // Appel de la fonction comparer_animaux
    int taille_resultat;
    Animal *resultat = comparer_animaux(tableau1, N1, tableau2, N2, &taille_resultat);

    // Affichage des résultats
    printf("Chevaux du premier tableau qui ne sont pas dans le second:\n");
    for (int i = 0; i < taille_resultat; i++) {
        printf("Categorie: %s, Poids: %d, Date de naissance: %s\n", resultat[i].categorie, resultat[i].poids, resultat[i].date_naissance);
    }

    // Libération de la mémoire allouée pour le résultat
    free(resultat);

    return 0;
}


// Fonction pour comparer les animaux
Animal* comparer_animaux(Animal tableau1[], int taille1, Animal tableau2[], int taille2, int *taille_resultat) {
    Animal *resultat = malloc(taille1 * sizeof(Animal));
    int nb_resultat = 0;

    for (int i = 0; i < taille1; i++) {
        if (strcmp(tableau1[i].categorie, "cheval") == 0) {
            int animal_present = 0;
            for (int j = 0; j < taille2; j++) {
                if (strcmp(tableau1[i].categorie, tableau2[j].categorie) == 0 &&
                    tableau1[i].poids == tableau2[j].poids &&
                    strcmp(tableau1[i].date_naissance, tableau2[j].date_naissance) == 0) {
                    animal_present = 1;
                    break;
                }
            }
            if (!animal_present) {
                resultat[nb_resultat++] = tableau1[i];
            }
        }
    }

    *taille_resultat = nb_resultat;
    return resultat;
}

Animal saisie_animal () {
    Animal a;
    
    printf("Categorie de l'animal : ");
    fgets(a.categorie, 20, stdin);
    a.categorie[strlen(a.categorie)-1] = '\0';
    printf("Poids en kg : ");
    scanf("%d", &a.poids);
    printf("Date de naissance au format jj/mm/aaaa : ");
    fgets(a.date_naissance, 11, stdin);
    a.date_naissance[strlen(a.date_naissance)-1] = '\0';
    return a;
}



//---------------------------------- Validation date
void isdatevalide1 (int j, int mois, int an){
    if (an > 0 && mois > 0 && mois <= 12 && j > 0 && j <= nbr_jour(mois, an))
        printf("La date %d/%d/%d est valide\n", j, mois, an);
    else  printf("Erreur: La date %d/%d/%d est invalide\n", j, mois, an);  
}

int saisirjour (void) {
    int jour;    
    printf("Saisir un jour : ");
    scanf("%d", &jour);
    return  jour;
}

int saisirmois (void) {
    int mois;    
    printf("Saisir un mois : ");
    scanf("%d", &mois);
    return  mois;
}

int saisiran (void) {
    int an;    
    printf("Saisir une année : ");
    scanf("%d", &an);
    return  an;
}

int nbr_jour (int mois, int an) {
    if (mois == 4 || mois == 6 || mois == 9 || mois == 11) {
        return 30;
    } else if (mois ==  2) {
        if (isbissextile(an)){
            return 29;
         }else{
             return 28;
        }
    } else {
         return 31;
    }
}

int isbissextile (int an) {
    if ((an % 4 == 0 && an % 100 != 0) || an % 400 ==  0) return 1;
    else return 0;
}