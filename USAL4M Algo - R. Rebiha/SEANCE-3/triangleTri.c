/* 
Exercice 8: 
- En entree: un numero N
- En sortie: imprimer un triangle rectangle et isocèle, rempli de "*" avec N lignes.
Par exemple si l'utilisateur tape 5 en entrée, le programme affiche sur 5 lignes le triangle suivant:

*
* *
* * *
* * * *
* * * * *
*/ 

#include<stdio.h>

int main()
{
  //Demande a l utilisateur la taille N de la table de multiplication
  int tailleTri = 0;
  //int tmp;
  printf("Donner la taille du triangle, SVP\n");
  scanf("%d", &tailleTri);

  for(int i=1; i<=tailleTri; i=i+1) // debut ligne de travaille
  {
    for(int j=1; j<=i; j=j+1) // pour chaque ligne imprimer i fois (index de la ligne courante)
    {
      printf("*");
    }//fin d'une ligne donc pensez au \n 
    printf("\n");
  }
  return 0;
}