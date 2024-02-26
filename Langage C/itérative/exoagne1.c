#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main() {
    int choix;
    
    do {
        printf("\n---------------------------------------------------------------------------------------------\n");
        printf("                               Bienvenue dans le menu                                          \n");
        printf("1 ------- Saisir une série de produit (Arrêt par réponse o/n) puis afficher le plus petit      \n");
        printf("2 ------- Saisir une série de produit (Arrêt par réponse o/n) puis afficher le plus grand MTTC \n");
        printf("3 --------------------------------------- Quitter ---------------------------------------------\n");
        printf("\nChoisissez une option: ");
        scanf("%d", &choix);

        if (choix == 1) {
            char nom[50], minnom[50];
            int id, minid, montant;
            char rep = 'o';
            double prix, quant, min = 99999999, minquant;
            
            for (; rep == 'o' || rep == 'O'; ) {
                printf("\nVeuillez saisir l'id du produit:  ");
                scanf("%d", &id);
                
                printf("\nVeuillez saisir le nom du produit:  ");
                while (getchar() != '\n'); 
                fgets(nom, sizeof(nom), stdin);
                nom[strcspn(nom, "\n")] = '\0';
                while (strlen(nom) == 0 || strcspn(nom, " \t\r\n") != strlen(nom)) {
                    printf("Erreur: Le nom du produit ne peut pas être vide ou contenir d'espaces.\n");
                    printf("\nVeuillez saisir le nom du produit:  ");
                    fgets(nom, sizeof(nom), stdin);
                    nom[strcspn(nom, "\n")] = '\0';
                }
                
                printf("\nVeuillez saisir le prix unitaire du produit:   ");
                scanf("%lf", &prix);
                printf("\nVeuillez saisir la quantite en stock :  ");
                scanf("%lf",&quant);
                printf("Voulez-vous saisir un autre produit ? (o/n) ");
                scanf(" %c", &rep);
                
                if (min > 0 && prix < min) {
                    min = prix;
                    minid = id;
                    strcpy(minnom, nom);
                    minquant = quant;
                }
            }
            printf("\nLe produit avec le prix le plus bas est:\nId:%d\nNom:%s\nPrix Unitaire:%lf\nQuantite En Stock:%lf\n", minid, minnom, min, minquant);
        } 

        if (choix == 2) {
            char nom[50], maxnom[50];
            int id, maxid;
            char rep = 'o';
            double prix1, quant1, max = 0, montant, maxquant, maxprix;
            do {
                printf("\nVeuillez saisir l'id du produit:  ");
                scanf("%d", &id);
                do {
                    printf("\nVeuillez saisir le nom du produit:  ");
                    while (getchar() != '\n');
                    fgets(nom, sizeof(nom), stdin);
                    nom[strcspn(nom, "\n")] = '\0'; 
                    printf("Erreur: Le nom du produit ne peut pas être vide ou contenir d'espaces.\n");
                    fgets(nom, sizeof(nom), stdin);
                    nom[strcspn(nom, "\n")] = '\0'; 
                }while (strlen(nom) == 0 || strcspn(nom, " \t\r\n") != strlen(nom));
                
                printf("\nVeuillez saisir le prix unitaire du produit:   ");
                scanf("%lf", &prix1);
                printf("\nVeuillez saisir la quantite en stock :  ");
                scanf("%lf",&quant1);
                montant = prix1 * quant1;
                
                if (max < montant) {
                    max = montant;
                    maxprix = prix1;
                    maxid = id;
                    strcpy(maxnom, nom);
                    maxquant = quant1;
                }
            } while (prix1 > 0 && quant1 > 0);
            
            printf("\nLe produit avec le prix le plus bas est:\n----- Id:%d\n-----Nom:%s\nPrix Unitaire:%lf\nQuantite En Stock:%lf\n", maxid, maxnom, max, maxquant);
        } 

        if (choix < 1 || choix > 3) {
            printf("Option invalide, veuillez entrer un nombre entre 1 et 2 : ");
        }
        
        printf("\nMerci !!!\n");
    } while (choix != 3);
    
    return 0;
}
