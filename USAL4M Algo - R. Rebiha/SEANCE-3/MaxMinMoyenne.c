/* 
Exercice 3: 
- Declarer un tableau affecté avec 10 entiers. 
Parcourez le tableau pour trouver l’entier le plus grand.  
Parcourez le tableau pour trouver l’entier le plus petit.
- Calculer la moyenne des valeurs du tableau.
*/ 

#include<stdio.h>

int main()
{
  int tabA[10] = {5,2,3,4,9,6,12,8,9,6}; 
  int leMaxCourant = tabA[0];
  int leMinCourant = tabA[0];
  int somme = 0;

  for(int i=0; i<10; i=i+1)
  {
    if(tabA[i] > leMaxCourant)
    {
      leMaxCourant = tabA[i];
    }
    if(tabA[i] < leMinCourant)
    {
      leMinCourant = tabA[i];
    }
    somme = somme + tabA[i];
  }
  printf("Le plus grand du tableau: %d \n", leMaxCourant);
  printf("Le plus petit du tableau: %d \n", leMinCourant);
  printf("Le moyenne du tableau: %d \n", somme / 10);

return 0;
}