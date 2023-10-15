/*
Exercice 1: 
- Ecrire une Fonction Bonjour qui ne prend aucun argument et qui 
affiche “Bonjour” a son appel depuis le main(). 
Type de Retour nom fonction (parametre) corps
*/

#include <stdio.h>

//DEFINITIONS des Fonctions 

void DisBonjourNumero(int varEntier){
	printf("Bonjour numero %d \n", varEntier);	
	//printf("Bonjour\n");
}

void DisBonjourChaineCaratere(char* varCharCaratere){
	printf("Bonjour numero %s \n", varCharCaratere);	
	//printf("Bonjour\n");
}

int main(){
	//APPELS FonctionS

	DisBonjourNumero(5);
	//.....
	DisBonjourNumero(1899);

	DisBonjourChaineCaratere("HELLO"); 
	char* mot = "HELLO";
    printf("%c\n", mot[2]);
	//char mot[5] = "HELLO";
	//char* motC = "TCHAU";
	//printf("%c\n", mot[2]); 
	//printf("%c\n", motC[2]); 

return 0;
}

