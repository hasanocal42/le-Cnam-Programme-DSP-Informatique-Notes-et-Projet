/*
Exercice 2: 
- Ecrire une fonction “puissanceDeux” qui prend un entier N en 
paramètre et retourne N*N à son appel. 
- Ecrire une fonction addition qui prend 2 entiers et retourne 
l’addition à son appel. 
- Ecrire un programme (une calculatrice), qui demande a 
l’utilisateur un caractère d’operation (e.g., “+”, “*”, …), 2 
entiers et retourne l’operation
*/

#include <stdio.h>

//DEFINITIONS une Fonctions

int puissanceDeux(int varA){
    int resultat = varA * varA;
    return resultat;
}

int addition(int vA, int vB){
    int resultatAddition = vA + vB;
    return resultatAddition;
}

int main(){
    int entierTaper;
    int entierA;
    int entierB;
    printf("Donner un entier\n");
    scanf("%d", &entierTaper);
    //APPELS Fonctions

    int puissDeux = puissanceDeux(entierTaper);
    printf("Resultat de la puissanc 2 : %d\n", puissDeux);

    printf("Donner un premier  entier\n");
    scanf("%d", &entierA);
    printf("Donner un deuxime entier\n");
    scanf("%d", &entierB);

    int additionValeur = addition(entierA, entierB);
    printf("Addition: %d\n", additionValeur);
    
return 0;
}