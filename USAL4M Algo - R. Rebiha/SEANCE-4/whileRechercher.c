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

 int main() {
  
  int TabA[8]={1,2,3,4,5,6,7,8};
  int entierTaper;
  bool trouver = false;

  printf("Donner l'entier a chercher dans le tableau SVP");

  scanf("%d", &entierTaper);

  int compteur = 0;

  while ((compteur < 8) && !(TabA[compteur] == entierTaper)){
    compteur = compteur + 1;
  }

  if(compteur < 8) {
    printf("Valeur présente dans le Tableau a l indice %d", compteur);
  }
  else{
    printf("Pas trouver");
  }
  
  return 0;
}