/* 
Exercice 7: 
Ecrire un programme qui 
- En entree: un numero N
- En sortie: affiche la table de multiplication jusqu'a N.
*/ 

#include<stdio.h>

int main()
{
  //Demande a l utilisateur la taille N de la table de multiplication
  int tailleTab = 0;
  //int tmp;
  printf("Donner la taille de la table de multiplication, SVP\n");
  scanf("%d", &tailleTab);

  for(int i=1; i<=tailleTab; i=i+1) // debut ligne de travaille
  {
    for(int j=1; j<=tailleTab; j=j+1) // pour chaque ligne imprime 4 fois
    {
      //tmp = i*j;
      //printf("%d",tmp);
      printf(" %d ", i*j);
    }//fin d'une ligne donc pensez au \n 
    printf("\n");
  }
  return 0;
}