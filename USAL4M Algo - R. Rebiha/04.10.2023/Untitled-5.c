#include <stdio.h>

int main()
{
    /* Declarer une variable qui est float quoi s'appelle taille affecterr une valeur ensuite imprimer écran */
    float taille = 1.70;
    printf("Je mesure %.2f \n", taille);
    
    double dtaille = 1.80;
    printf("Maintenant %.2lf", dtaille);
    
    double etaille = 3.2e5;
    char    c = 'A';
    printf("Mon carartère:%c \n",c);
    
    int typeSize = sizeof(c);
    printf("\n %d", typeSize);
    typeSize = sizeof(dtaille);
    printf("\n %d", typeSize);

    return 0;
}