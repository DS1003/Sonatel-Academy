#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>


#define LONGUEUR_MAX_LOGIN 20
#define LONGUEUR_MAX_MDP 20

// Structure pour stocker les informations de connexion
typedef struct {
    char login[LONGUEUR_MAX_LOGIN];
    char motDePasse[LONGUEUR_MAX_MDP];
} Identifiants;

// Fonction pour vérifier les identifiants de connexion
int verifierIdentifiants(Identifiants *identifiants, int nombreIdentifiants, char *login, char *motDePasse) {
    for (int i = 0; i < nombreIdentifiants; i++) {
        if (strcmp(identifiants[i].login, login) == 0 && strcmp(identifiants[i].motDePasse, motDePasse) == 0) {
            return 1; // Identifiants valides
        }
    }
    return 0; // Identifiants invalides
}

int menuAdmin() {
    // Définition du menu de l'administrateur
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

int menuEtudiant() {
    // Définition du menu de l'étudiant
    int choix = 0;
    do {
        printf("--------------------------------------------------------------------------\n");
        printf("\t\t\tBienvenue dans le menu de l'apprenant :\n");
        printf("--------------------------------------------------------------------------\n");
        printf("1 ---------- GESTION DES ÉTUDIANTS\n");
        printf("2 ---------- GÉNÉRATION DE FICHIERS\n");
        printf("3 ---------- MARQUER SA PRÉSENCE\n");
        printf("4 ---------- Message (0)\n");
        printf("5 ---------- Déconnexion\n");
        printf("\n---------- Entrez votre choix : ");
        scanf("%d", &choix);
        if (choix < 1 || choix > 5) {
            printf("Choix invalide. Veuillez entrer un choix entre  1 et 5.\n");
        }
    } while (choix < 1 || choix > 5);
    return choix;
}

int main() {
    // Création des fichiers pour stocker les identifiants
    FILE *fichierAdmin = fopen("admin.txt", "r");
    FILE *fichierEtudiant = fopen("etudiant.txt", "r");

    if (fichierAdmin == NULL || fichierEtudiant == NULL) {
        printf("Erreur lors de l'ouverture des fichiers.\n");
        return 1;
    }

    // Variables pour stocker les identifiants
    Identifiants identifiantsAdmin[100]; // Pour stocker jusqu'à 100 identifiants d'administrateur
    Identifiants identifiantsEtudiant[100]; // Pour stocker jusqu'à 100 identifiants d'étudiant

    int nombreIdentifiantsAdmin = 0;
    int nombreIdentifiantsEtudiant = 0;

    // Lecture des identifiants de l'admin
    while (fscanf(fichierAdmin, "%s %s", identifiantsAdmin[nombreIdentifiantsAdmin].login, identifiantsAdmin[nombreIdentifiantsAdmin].motDePasse) == 2) {
        nombreIdentifiantsAdmin++;
    }
    fclose(fichierAdmin);

    // Lecture des identifiants de l'étudiant
    while (fscanf(fichierEtudiant, "%s %s", identifiantsEtudiant[nombreIdentifiantsEtudiant].login, identifiantsEtudiant[nombreIdentifiantsEtudiant].motDePasse) == 2) {
        nombreIdentifiantsEtudiant++;
    }
    fclose(fichierEtudiant);

    // Variables pour l'authentification
    char saisieLogin[LONGUEUR_MAX_LOGIN];
    char *saisieMotDePasse;

    // Authentification
    do {
        printf("---------------- Connexion ----------------\n\n");
        printf("Login : ");

        // Saisie du login
        fgets(saisieLogin, LONGUEUR_MAX_LOGIN, stdin);
        saisieLogin[strcspn(saisieLogin, "\n")] = 0; // Supprime le caractère de nouvelle ligne
        if (strlen(saisieLogin) == 0) {
            printf("\nVous avez laissé le champ vide. Veuillez rentrer votre login.\n");
            continue;
        }

        // Saisie du mot de passe
        saisieMotDePasse = getpass("Mot de passe: ");
        if (strlen(saisieMotDePasse) == 0) {
            printf("\nVous avez laissé le champ vide. Veuillez entrer votre mot de passe.\n");
            continue;
        }

        // Vérification des identifiants
        if (verifierIdentifiants(identifiantsAdmin, nombreIdentifiantsAdmin, saisieLogin, saisieMotDePasse)) {
            // Menu pour l'admin
            menuAdmin();
        } else if (verifierIdentifiants(identifiantsEtudiant, nombreIdentifiantsEtudiant, saisieLogin, saisieMotDePasse)) {
            // Menu pour l'étudiant
            menuEtudiant();
        } else {
            printf("Login ou mot de passe invalides.\n");
        }

    } while (!(verifierIdentifiants(identifiantsAdmin, nombreIdentifiantsAdmin, saisieLogin, saisieMotDePasse)) || !(verifierIdentifiants(identifiantsEtudiant, nombreIdentifiantsEtudiant, saisieLogin, saisieMotDePasse)));

    return 0;
}