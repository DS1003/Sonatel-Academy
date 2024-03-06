#include <stdio.h>

int main(){
    //déclaration des variables
    int a, b, res;
    char op;
    //Saisie et récupération des valeurs et de l'opérateur
    printf("Vous allez rentrer un entier a puis opérateur ('+', '-', '/' ou '*') puis le deuxième entier b pour obtenir le résultat du programme\n");
    scanf("%d %c %d", &a, &op, &b);
    //Vérification, calcul puis affichage
    if (op == '+'){
        res = a+b;
        printf("Le résultat de l'opération %d %c %d = %d\n", a, op, b, res);
    }else if (op == '-'){
        res = a-b;
        printf("Le résultat de l'opération %d %c %d = %d\n", a, op, b, res);
    }else if (op == '/')
    {
        res = a/b;
        printf("Le résultat de l'opération %d %c %d = %d\n", a, op, b, res);
    }else if (op == '*'){
        res = a*b;
        printf("Le résultat de l'opération %d %c %d = %d\n", a, op, b, res);
    }
    return 0;
}