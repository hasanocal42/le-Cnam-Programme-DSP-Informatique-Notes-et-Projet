/* 
Exercice 1: 
Declarer un tableau de 8 entiers. 
Affectez les valeurs directement.  
Ecrire une boucle For pour afficher 
toutes les valeurs du tableau.
*/ 

#include<stdio.h>

int main()
{
  //int tabA[8] = {2,3,4,5,8,1,0,2}; 
  int tabA[8]; 

  printf("Donnez les 8 valeurs du tableau");
  scanf("%d", &tabA[0]);
  scanf("%d", &tabA[1]);
  scanf("%d", &tabA[2]);
  scanf("%d", &tabA[3]);  
  scanf("%d", &tabA[4]);
  scanf("%d", &tabA[5]);
  scanf("%d", &tabA[6]);
  scanf("%d", &tabA[7]);

  printf("Au rdc : %d\n", tabA[0]);
  printf("Etage suivant : %d\n", tabA[1]);
  printf("Etage suivant : %d\n", tabA[2]);
  printf("Etage suivant : %d\n", tabA[3]);
  printf("Etage suivant : %d\n", tabA[4]);
  printf("Etage suivant : %d\n", tabA[5]);
  printf("Etage suivant : %d\n", tabA[6]);
  printf("Etage suivant : %d\n", tabA[7]);

return 0;
}




