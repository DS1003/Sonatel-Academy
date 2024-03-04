#include <stdio.h>
#include <string.h>

#define numfixe 9 // Longueur totale du numéro
#define taille_num  19

void validnumfixe ();
void validnummobile ();

int main() {
    int choix;
    do {
        printf("\n---------------------------------------------------------------------------------------------\n");
        printf("                               Bienvenue dans le menu                                          \n");
        printf("1 ------- Saisir un numéro fixe puis tester si c'est valide ou pas                             \n");
        printf("2 ------- Saisir un numéro de téléphone portable, teste puis affiche l'opérateur               \n");
        printf("3 --------------------------------------- Quitter ---------------------------------------------\n");
        printf("\nChoisissez une option: ");
        scanf("%d", &choix);
        //------------------------------------------- choix 1 ------------------------------------------------------
        if  (choix == 1) {
            validnumfixe();
        } 
        //------------------------------------------- choix 2 ------------------------------------------------------
        if (choix ==  2) {
            char tel_mobile [taille_num + 1]; 
            
            printf("Veuillez entrer votre numéro de téléphone portable (+221) 77 001 00 00 ou 00221 70 007 00 00) : ");
            fgets(tel_mobile , sizeof(tel_mobile ), stdin);

            tel_mobile [strcspn(tel_mobile , "\n")] = '\0';

            if (strncmp(tel_mobile, "(+221)", 5) == 0 && (strlen(tel_mobile ) != taille_num)){
                    printf("Numéro invalide. Le numéro doit contenir exactement %d chiffres.\n", taille_num);
            } 
            if  (strncmp(tel_mobile, "00221" ,4) == 0 && strlen(tel_mobile) == taille_num - 1) {
                    printf("Numéro invalide. Le numéro doit contenir exactement %d chiffres.\n", taille_num - 1);
            }

            if (strncmp(tel_mobile , "(+221)", 5) != 0 && strncmp(tel_mobile , "00221", 5) != 0) {
                printf("Numéro invalide. Le numéro doit commencer par \"(+221)\" ou \"00221\".\n");
            }

            // Vérifier le format des caractères restants
            if (strncmp(tel_mobile, "(+221)", 5) != 0 && tel_mobile [6] != ' ' || tel_mobile [9] != ' ' || tel_mobile [13] != ' ' || tel_mobile [16] != ' ') {
                printf("Numéro invalide. Format incorrect pour les chiffres restants.\n");
            }
            printf("Numéro Valide\n");
            if (tel_mobile[8] == '7' || tel_mobile[8] == '8' &&  strncmp(tel_mobile, "(+221)", 5) ){
                printf("L'opérateur est : Orange\n");
            } else if (tel_mobile[8] == '7' || tel_mobile[8] == '8' &&  strncmp(tel_mobile, "00221", 5) ){
                printf("L'opérateur est : Orange\n");
            } 
            if (tel_mobile[7] == '6' || tel_mobile[8] == '8' &&  strncmp(tel_mobile, "(+221)", 5) ){
                printf("L'opérateur est : Orange\n");
            } 
            
        }
        //-------------------------------------- choix 3 - Quitter -------------------------------------------------
        if (choix ==  3){
            printf("Merci & Aurevoir !!!\n"); 
        }   
    } while (choix != 3);
    return 0;
}



void validnumfixe () {
    char input[numfixe + 1]; // +1 pour le caractère nul
            printf("Veuillez entrer un numéro de téléphone fixe (33#######) : ");
            fgets(input, sizeof(input), stdin);
            // Supprimer le caractère de nouvelle ligne ajouté par fgets
            input[strcspn(input, "\n")] = '\0';
            // Vérifier la longueur du numéro
            if (strlen(input) != numfixe) {
                printf("Numéro invalide. Le numéro doit contenir exactement %d chiffres.\n", numfixe);
                return 1;
            }
            // Vérifier que les caractères sont tous numériques
            for (int i = 0; i < numfixe; i++) {
                if (input[i] < '0' || input[i] > '9') {
                    printf("Numéro invalide. Le numéro doit contenir uniquement des chiffres.\n");
                    return 1;
                }
            }
            // Vérifier si le numéro commence par "33"
            if (strncmp(input, "33", 2) != 0) {
                printf("Numéro invalide. Le numéro doit commencer par \"33\".\n");
                return 1;
            }
            printf("Numéro valide.\n");
}


void validnummobile () {
    char tel_mobile [taille_num + 1];       
            printf("Veuillez entrer votre numéro de téléphone portable (+221) 77 001 00 00 ou 00221 70 007 00 00) : ");
            fgets(tel_mobile , sizeof(tel_mobile ), stdin);

            tel_mobile [strcspn(tel_mobile , "\n")] = '\0';

            if (strncmp(tel_mobile, "(+221)", 5) == 0 && (strlen(tel_mobile ) != taille_num)){
                    printf("Numéro invalide. Le numéro doit contenir exactement %d chiffres.\n", taille_num);
            } 
            if  (strncmp(tel_mobile, "00221" ,4) == 0 && strlen(tel_mobile) == taille_num - 1) {
                    printf("Numéro invalide. Le numéro doit contenir exactement %d chiffres.\n", taille_num - 1);
            }

            if (strncmp(tel_mobile , "(+221)", 5) != 0 && strncmp(tel_mobile , "00221", 5) != 0) {
                printf("Numéro invalide. Le numéro doit commencer par \"(+221)\" ou \"00221\".\n");
            }

            // Vérifier le format des caractères restants
            if (strncmp(tel_mobile, "(+221)", 5) != 0 && tel_mobile [6] != ' ' || tel_mobile [9] != ' ' || tel_mobile [13] != ' ' || tel_mobile [16] != ' ') {
                printf("Numéro invalide. Format incorrect pour les chiffres restants.\n");
            }
            printf("Numéro Valide\n");
            if (tel_mobile[8] == '7' || tel_mobile[8] == '8' &&  strncmp(tel_mobile, "(+221)", 5) ){
                printf("L'opérateur est : Orange\n");
            } else if (tel_mobile[8] == '7' || tel_mobile[8] == '8' &&  strncmp(tel_mobile, "00221", 5) ){
                printf("L'opérateur est : Orange\n");
            } 
            if (tel_mobile[7] == '6' || tel_mobile[8] == '8' &&  strncmp(tel_mobile, "(+221)", 5) ){
                printf("L'opérateur est : Orange\n");
            } 
}