#include <stdio.h>

int main() 
{
    printf("laNote ?\n");

    int laNote;
    scanf("%d", &laNote);

    if((laNote >= 0) && (laNote < 7)) 
    {
        printf("Niveau F \n");
    } 
    else if((laNote >= 7) && (laNote < 10)) 
    {
        printf("Niveau E\n");
    } 
    else if((laNote >= 10) && (laNote < 15)) 
    {
        printf("Niveau B \n");
    } 
    else if((laNote >= 15) && (laNote <= 20)) 
    {
        printf("Niveau A\n");
    } 
    else 
    {
        printf("laNote non valide!\n");
    }
    printf("Au revoir \n");

    return (0);
}

/* tester une note, de 7 a 10 ta C, de 10 a 12 ta B, et de 12 a 20 ta A 
Donner une note
si (laNote>0) && (laNote<7) imprimer "niveau F"
sinon si (laNote>7) && (laNote<10) imprimer "niveau E"
sinon si (laNote>=10) && (laNote<15) imprimer "niveau B"
sinon si (laNote>=15) && (laNote<=20) imprimer "niveau A"
sinon imprimer note non valide */