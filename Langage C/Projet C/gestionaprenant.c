#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// ========================================================= Structure de données =========================================================
typedef struct 
{
    int j;
    int mois;
    int an;
} Date;

// Définition du type User
typedef struct {
    char login [50];
    char motDePasse[50];
    int typeUtilisateur; // 0 pour étudiant, 1 pour administrateur
} User;


// Définition du type Student
typedef struct {
    int id;
    char nom[50];
    char prenom[50];
    char matricule[10];
    int presence[31]; // 1 pour présent, 0 pour absent
    int retard; // nombre de minutes de retard
    char messages[1000]; // 
    int nbMessages;
    int etat;
    char classe[5];
    int cumulretard; // quota maximal d'absences avant renvoi, paramétrable
    int nbAbsences;
} Etudiant;


// Définition du type File

typedef struct {
    int id;
    char nom[50];
    char prenom[50];
    char matricule[50];  //Matricule ADM-SD0001
    char motdepasse[8];   // Mot de passe : admin
} Admin;

typedef struct {
    int id;
    char expediteur[50];
    char contenue [1000];
    char destinaire[50]; 
    Date datenvoie;
    int etat;
} Message;

typedef struct {
    int id;
    char libele [30];
    Etudiant  *etudiants;
    int nbr_etudiant;
} Classe;

// ----------------------------------------------------------- Prototype ------------------------------------------------------------
int connection (char login[], char motdepasse[]);
int menuAdmin ();

// -------------------------------------------------------------- Main --------------------------------------------------------------

int main () {
    char login[10], motdepasse[8];
    if (connection(login, motdepasse)) {
        int choix = 0;
        choix = menuAdmin();
    } else {
        exit(EXIT_FAILURE);
    }
    return 0;
}


// -------------------------------------------------------------- Implémentationn ---------------------------------------------------

int menuAdmin () {
    int choix = 0;
    do {
        printf("--------------------------------------------------------------------------\n");
        printf("\t\t\tBienvenue dans le menu de l'administrateur:\n");
        printf("--------------------------------------------------------------------------\n");
        printf("1 ---------- GESTION DES ÉTUDIANTS\n");
        printf("2 ---------- GÉNÉRATION DE FICHIERS\n");
        printf("3 ---------- MARQUER LES PRÉSENCES\n");
        printf("4 ---------- ENVOYER UN MESSAGE\n");
        printf("5 ---------- Quitter\n");
        printf("\n---------- Entrez votre choix : ");
        scanf("%d", &choix);
        if (choix < 1 || choix > 5) {
            printf("Choix invalide. Veuillez entrer un choix entre  1 et 5.\n");
        }
    } while (choix < 1 || choix > 5);
    return choix;
}

int connection (char login[], char motdepasse[]) {
    printf("--------------------------------------------------------------------------\n");
    printf("\t\tBienvenue\n");
    printf("Veuillez saisir  votre login: ");
    scanf("%s",login);
    printf("Veuillez saisir votre mot de passe: ");
    scanf("%s",motdepasse);
    if ((strcmp(login, "admin") != 0) || (strcmp(motdepasse,"admin")!=0)) {
        printf("Login ou mot de passe incorrect.\n");
        return 0;
    } else {
        printf("Connexion reussie.\n");
        return 1;
    }
}