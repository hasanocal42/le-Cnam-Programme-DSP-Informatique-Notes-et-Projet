/* 
Exercice 5:
Declarer un tableau TabA de 8 entiers.
-l’utilisateur tape au clavier un entiers.
-le programme cherche la valeur dans le tableau. Si la valeur
est présente, on retourne un message “Oui” sinon on retourne
“Non”. 
*/ 

#include <stdio.h>
#include <stdbool.h>

 int main()
 {
  int TabA[8]={1,2,3,4,5,6,7,8};
  int entierTaper;
  bool trouver = false;

  printf("Donner l'entier a chercher dans le tableau SVP");

  scanf("%d", &entierTaper);

  for (int i=0; i<=7; i=i+1)
  {
    if(TabA[i] == entierTaper)
    {
      trouver = true;
    }
  }
  if(trouver == true)
  {
    printf("Valeur présente dans le Tableau");
  }
  else
  {
    printf("Pas trouver");
  }
  return 0;
}