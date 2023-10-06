/* 
Exercice 9: 
Écrire un programme qui 
fait la multiplication des entrees jusqu’a ce que l’utilisateur entre 0. 
(Tips: utiliser une boucle “do … while”.
*/ 

#include<stdio.h>

int main()
{
  //Demande a l utilisateur la taille N de la table de multiplication
  int valeurTaper = 1;
  int multiplicationTotal = 1;
  //int tmp;
 
  do
  {
    multiplicationTotal = multiplicationTotal * valeurTaper;
    printf("Donner un nombre different de zero: \n");
    scanf("%d", &valeurTaper);
  }
  while(valeurTaper != 0);{
  printf("voici le total de la multiplicationTotal: %d \n", multiplicationTotal);
  }
  return 0;
}
