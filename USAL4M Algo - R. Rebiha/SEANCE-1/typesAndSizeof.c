#include <stdio.h>

int main()
{
     /* Declarer une variable qui est float quoi s'appelle taille affecterr une valeur ensuite imprimer écran */
    float taille = 1.60;
    //printf("Je mesure %.2fm\n", taille);

    double dtaille = 1.80;
    //printf("Je mesure %.2lfm\n", dtaille);

    double etaille = 3.2e5;
    //printf("result %lf \n", etaille);

    char lettre = '@';
    //printf("mon char %c", lettre);

    printf("Taille de float = %ld\n", sizeof(taille));  
    printf("Taille de double = %ld\n", sizeof(dtaille)); 
    printf("Taille de char = %ld", sizeof(lettre)); 
    return (0);
}
