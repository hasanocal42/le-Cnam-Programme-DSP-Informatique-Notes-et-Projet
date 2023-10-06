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

  for(int i=0; i<=7; i=i+1)
  {
    scanf("%d", &tabA[i]);
  }

  for(int i=0; i<=7; i=i+1){
    printf("Etage :%d\n", tabA[i]);
  }
return 0;
}