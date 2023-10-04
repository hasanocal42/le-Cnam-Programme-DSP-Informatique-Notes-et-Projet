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