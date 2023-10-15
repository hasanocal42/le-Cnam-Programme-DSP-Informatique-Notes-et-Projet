=======================
Fiche Resumer - Boucles
=======================

================
While - TANT QUE
================

while (condition){
	Instruction1;
	....
	InstructionN;
}
Tant que "condition" est vrai: Repeter "Instruction1 ... InstructionN"

- While avec un compteur

#include <stdio.h>

int main (){
	int compteur = 0; //Declaration et initialisation du compteur
	while (compteur < 10){
		printf("Bonjour");
		compteur = compteur + 1;
	} 
	return 0;
}

- While avec un evenement

#include <stdio.h>

int main (){
	int valeurTaper = 1;
		while (valeurTaper != 0){
			printf("Donner une valeur differente de zero");
			scanf("%d", &valeurTaper);
		} 
	return 0;
}

======================
For - Pour chaque tour
======================

#include <stdio.h>

int main (){
	for(int i=0; i<10; i++){
		printf("Bonjour");
	} 
	return 0;
}