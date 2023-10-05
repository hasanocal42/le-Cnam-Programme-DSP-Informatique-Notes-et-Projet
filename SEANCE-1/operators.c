#include <stdio.h>
#include <stdbool.h>

int main()
{
    int age = 31;
    float taille = 1.32; 
    /* Regle au barca : Resultat */
    bool resultEntrerStade = (age > 11) && (taille > 1.20);
    printf("Result = %d", resultEntrerStade);

    return (0);
}
/* 
Le OU logic s'ecrit ||
Le ET logic s'ecrit &&
Le NON logic s'ecrit !
*/