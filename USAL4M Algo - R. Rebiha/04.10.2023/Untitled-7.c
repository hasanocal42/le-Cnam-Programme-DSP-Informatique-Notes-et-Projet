#include <stdio.h>
#include <stdbool.h>

int main()
{
    int Age = 14;
    float   taille = 1.32;
    /* Regle au barca : Resultat */
    bool    resultatEntrerStade = (Age > 11)&&(taille>1.2);
        printf("Resultat Entre Stade %d", resultatEntrerStade);
    
    return 0;
}

/* 
Le OU logic s'ecrit ||
Le ET logic s'ecrit &&
Le NON logic s'ecrit !
*/