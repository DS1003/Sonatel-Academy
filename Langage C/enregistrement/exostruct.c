#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int autoIdEtudiant = 99;
typedef struct
{
    int j, m, a;

} DATE;

typedef struct
{
    int id;
    char matricule[10];
    char nom[50];
    char prenom[50];
    DATE dn;

} ETUDIANT;

typedef struct
{
    int id;
    char libelle[50];
    int coef;

} MATIERE;

typedef struct
{
    char libelle[50];
    MATIERE matieres[10];
    ETUDIANT etudiants[100];
    int nbrEtudiant;
    int nbrMatiere;
    enum
    {
        L1 = 1,
        L2,
        L3,
        M1,
        M2,
        M3
    }niveau;

} CLASSE;

typedef struct
{
    ETUDIANT etudiant;
    MATIERE matiere;
    float note;
    enum
    {
        DEVOIR,
        EXAMEN
    }type_eval;

} EVALUATION;

// prototype
void afficherDate(DATE);
DATE saisieDate(void);
int saisirInt(int, int, char[]);
ETUDIANT saisirEtudiant();
void afficherEtudiant (ETUDIANT);
int remplirTabEtudiant (ETUDIANT tab[]);
void genererMatricule  (char matricule[10], ETUDIANT  etudiant);



int main()
{
    enum jour{LUNDI = 1,MARDI, MERCREDI, JEUDI,VENDREDI,SAMEDI,DIMANCHE};
    enum jour j;
    j = LUNDI;
    //afficherDate(saisieDate());
    ETUDIANT e = saisirEtudiant();
    char matricule [10];

    genererMatricule(matricule, e);
    
    printf("Le matricule de l'etudiant est : %s\n", matricule);
    

    return 0;
}



DATE saisieDate(void)
{
    DATE d;
    puts("Entrez une date [j,m,a]");
   d.j = saisirInt(1, 31, "entrez le jour");
   d.m = saisirInt(1, 12, "entrez le mois");
   d.a = saisirInt(1, 2024, "entrez l'année");
    return d;
}
void afficherDate(DATE a)
{
    printf("la date est %d-%d-%d", a.j, a.m, a.a);
}
int saisirInt(int min, int max, char msg[])
{
    int x;
    do
    {
        puts(msg);
        scanf("%d", &x);
    } while (x<min || x>max);

    return x;
}
ETUDIANT saisirEtudiant(){
    ETUDIANT e;
    e.id = ++autoIdEtudiant;
    puts("Donnez le nom :");
    scanf("%s", e.nom);
    puts("Donnez le prénom :");
    scanf("%s", e.prenom);
    e.dn = saisieDate();
    return e;

}

void afficherEtudiant (ETUDIANT  e){
    printf("L'etudiant de nom %s %s a pour id: %d\n" ,e.nom, e.prenom, e.id );
}

int remplireTabEtudiant (ETUDIANT etudiants[100]) {
    //remplir le tableau en lui demandant après chaque saisie s'il veut ressaisir un  autre étudiant ou non
    int i=0;
    char reponse='y';
    do {
        etudiants[i]=saisirEtudiant();
        printf("\ndesirez vous ajouter un autre étudiant ? ");
        while ((reponse!='o') && (reponse!='O') && (reponse!='n') && (reponse!='N')){
            printf("\nVeuillez répondre par 'oui' ou 'non'\n");
            printf("Desirez vous ajouter un autre étudiant ? ");
            scanf("%s",&reponse);
        }
        if((reponse=='o')||(reponse=='O')){
            i++;
        }
    }while ((reponse=='y')||(reponse=='Y'));
    return i;
}






void genererMatricule  (char matricule[10], ETUDIANT  etudiant) {
    //matricule ex: MAT-PM0001 (MAT-1èrelettre prénom+1èrelettre nom + id)
    sprintf(matricule,"MAT-%c%c%04d", toupper(etudiant.prenom[0]), toupper(etudiant.nom[0]), etudiant.id);
}


