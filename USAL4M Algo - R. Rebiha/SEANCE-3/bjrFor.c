/* 
Exercice 3: 
Ecrire une boucle For qui affiche 100 fois les “Bonjours”. 
Modifier le programme pour qu’il indexes les “Bonjours” par un entier. 
Nous devons obtenir en sortie écran:
1 Bonjour
2 Bonjour
3 Bonjour
…
100 Bonjour
*/ 

#include<stdio.h>

int main(){

  for(int i=1; i<=100; i=i+1){
    printf("[%d] Bonjour\n", i);
  }

  return 0;
}