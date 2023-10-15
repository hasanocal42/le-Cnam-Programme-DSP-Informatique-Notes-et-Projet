=======================
Fiche Resumer- Tableaux
=======================

Les tableaux allouent des espaces memoires pour chaque cellule et attribuent un index pour chaque cellule. 

- Declaration:
Type -- nom -- [ taille ] -- = { les elements };
int monTableau [5] = {1, 5, 8, 3, 9};
char monTabChar [4] = {'a', 'z', 'e', 'k'};
- Lecture d'une valeur a un indice donné
int tmp = monTableau[0]; 
- Ecriture dans une cellule a un indice donné
monTableau[3] = 6;

- Operations:
 - Parcourir avec une boucle
 	Exemple avec For: 
 		#include <stdio.h>
 		int main (){
 			int monTableau [5] = {1, 5, 8, 3, 9};
 			//Parcourt
 			for(int i=0; i<5; i++){
 				//instructions pour chaque cellule
 				printf("Valeur dans la cellule %d est: %d", i, monTableau[i]);
 			}
 			return 0;
 		}