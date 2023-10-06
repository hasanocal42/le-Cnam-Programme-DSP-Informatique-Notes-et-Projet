/* 
Exercice 2: 
Modifier le programme de l’exercice 1 pour que 
-l’utilisateur tape au clavier 8 entiers. 
- les valeurs sont sauvés dans un tableau. 
- L’utilisateur tape un index du tableau et le programme 
retourne la valeur.
*/ 

#include<stdio.h>

int main()
{
  int tabA[8]; 
  int indexDemander;

  printf("Donnez les 8 valeurs du tableau");

  for(int i=0; i<=7; i=i+1)
  {
    scanf("%d", &tabA[i]);
  }

  printf("Donnez un index du tableau entre 0 et 7\n");
  scanf("%d", &indexDemander);
  printf("A l'index %d on trouve la valeur: %d \n",indexDemander, tabA[indexDemander]);

return 0;
}