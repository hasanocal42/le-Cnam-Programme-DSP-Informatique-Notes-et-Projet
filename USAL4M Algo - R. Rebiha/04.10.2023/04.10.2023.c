#include <stdio.h>

int main() {
    printf("Bom Dia!");
    return 0;
}

------------------------------------

#include <stdio.h>

int main()
{
    int Age = 31;
    printf("Je m'appelle Hasan j'ai %d", Age);
    return 0;
}

--------------------------------------

#include <stdio.h>

int main()
{
    int Age = 31;
    printf("Je m'appelle Hasan j'ai %d \n", Age);
    
    Age = Age + 10;
    printf("10 ans plus tard, j'ai %d", Age);
    
    return 0;
}

--------------------------------------

#include <stdio.h>

int main()
{
    int VarA;
    int VarB = 55;
    /* mettre dans VarB aprés multiplé par 183479 et mettre le resultat dans VarA*/
    /* question: Prendre la valeurde VarB, la multiplier par 183479 mettre le resultat dans VarA*/
    VarA = VarB * 183479;
    printf("Le resultat VarA : %d, VarB %d", VarA, VarB);
    return 0;
}

----------------------------------------

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

------------------------------------------

#include <stdio.h>
#include <stdbool.h>

int main()
{
    bool gagner = false;
    bool dormir = true;
    
    printf("gagner? %d\n", gagner);
    printf("dormir? %d\n", dormir);
    
    bool bill = (1>2);
    printf("\nbill joe:%d", bill);
    
    return 0;
}

--------------------------------------------

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

----------------------------------------------

#include <stdio.h>

int main()
{
    
        printf("Donnez la note please");
        //int laNote;
        double laNote;
        //scanf("%d", &laNote);
        scanf("%lf", &laNote);
        //printf("Merci, laNote reçu : %d", laNote);
        printf("Merci, laNote reçu : %lf", laNote);
        
        /* Demander num Etudiant et le groupe etudiant (A,B,C,...)*/
        
        printf("Donnez le num Etudiant et la lettre du groupe");
        int leNum;
        char lettreGroupe;
        scanf("%d %c", &leNum, &lettreGroupe);
        printf("merci le num reçu:%d du groupe%c",leNum, lettreGroupe);
        
    return 0;
}

----------------------------------------------

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