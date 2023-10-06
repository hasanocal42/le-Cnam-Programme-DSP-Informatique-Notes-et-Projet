/* 
Exercice 4: 
Ecrire une boucle For qui 
calcule la somme des 1000 premiers entiers.
100 Bonjours
*/ 

#include<stdio.h>

int main()
{
  int somme = 0;
  for(int i=1; i<=1000; i=i+1)
  {
    somme = somme + i;
  }
    printf("La somme des 1000 premiers nombres est : %d ", somme);
  return 0;
}