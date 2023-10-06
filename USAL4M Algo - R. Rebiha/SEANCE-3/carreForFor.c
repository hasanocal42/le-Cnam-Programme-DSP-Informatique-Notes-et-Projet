/* 
Exercice 6: 
À l’aide de boucles For imbriqués, ecrire un program qui prend un entier N en entrée et qui affiche un rectangle de taille N*N contenant le caractère “#”. 
Exemple: Si l’utilisateur entre 4 nous obtenons:
****
****
****
****
*/ 

#include<stdio.h>

int main(){
  //Demande a l utilisateur la taille N du carre
  int N = 0;
  printf("Donner la taille du carre, SVP\n");
  scanf("%d", &N);

  for(int i=1; i<=N; i=i+1){// debut ligne de travaille
    for(int j=1; j<=N; j=j+1){// pour chaque ligne imprime 4 fois
      printf("#");
    }//fin d'une ligne donc pensez au \n 
    printf("\n");
  }
  return 0;
}





