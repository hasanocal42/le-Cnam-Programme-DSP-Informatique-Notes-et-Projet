/* 
Exercice 4: 
Declarer un tableau TabA de 8 entiers. 
- Afficher les valeurs du tableau dans le sens inverse.
- Cree un tableau TabB qui est l’inverse du TabA.
*/ 

#include <stdio.h>

int main()
{
  int TabA[8]={1,2,3,4,5,6,7,8};
  int TabB[8];
  int debut = 0;
  int fin = 7;
  
  while((debut<=7) && (fin>=0))
  {
    TabB[debut] = TabA[fin];
    debut = debut + 1;
    fin = fin - 1;
  }
  //affichage TabB
  printf("TabB a bien ete inverse:");
  for (int i=0; i<=7; i=i+1)
  {
    printf("%d ", TabB[i]);
  }
  
  return 0;
}