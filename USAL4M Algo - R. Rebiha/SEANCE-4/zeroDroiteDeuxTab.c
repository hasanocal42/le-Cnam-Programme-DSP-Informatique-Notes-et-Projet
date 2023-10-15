/* 
Exercice 8: 
Declarer un tableau TabA de 8 entiers. Ecrire in programme qui 
vérifie si il y a deux valeurs identiques consécutives.
*/ 

#include <stdio.h>
#include <stdbool.h>

 int main() {
  
  int etageDsTabB = 0;
  int TabA[15]={3,0,5,7,0,2,4,0,0,7,9,6,0,8,5};
  int TabB[15];

  for(int i=0; i<15; i++){
    if(TabA[i] != 0){
      TabB[etageDsTabB] = TabA[i];
      etageDsTabB = etageDsTabB + 1;
    } 
  }

  for (int j = etageDsTabB; j<15; j++){
    TabB[j] = 0;
  }

 for(int k=0; k<15; k++){
    printf("%d ", TabB[k]);
  }

return 0;
}