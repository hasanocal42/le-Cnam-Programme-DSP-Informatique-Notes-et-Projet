#include <stdio.h>

int main()
{
    
        printf("laNote?");
        int laNote;
        scanf("%d", &laNote);
        if(laNote>=10)
        {
        printf("Bravo!");
        }
        //printf("Aurevoir");
        {
            printf("Tente à Nouveau!");
        }
        printf("Aurevoir");
        
    return 0;
}

/* tester une note, de 7 a 10 ta C, de 10 a 12 ta B, et de 12 a 20 ta A 
Donner une note
si (Note>0) && (Note<7) imprimer "niveau F"
sinon si (Note>7) && (Note<10) imprimer "niveau E"
sinon si (Note>=10) && (Note<15) imprimer "niveau B"
sinon si (Note>=15) && (Note<=20) imprimer "niveau A"
sinon imprimer note non valide */

#include <stdio.h>
#include <stdbool.h>

int main()
{
    printf("laNote?");
    int laNote;
    scanf ("%d", &laNote);
    if  ((laNote > 0) && (laNote < 7))
    {
        printf  ("la lettre:F");
    }    
    else if ((laNote >= 7) && (laNote < 10))
    {
        printf  ("la lettre:E");
    }
    else if ((laNote >= 10) && (laNote < 15))
    {
        printf  ("la lettre:B");
    }
    else if ((laNote >= 15) && (laNote < 20))
    {
        printf  ("la lettre:A");
    }
    else
    {
        printf  ("Note non valide");
    }
}

return  0;