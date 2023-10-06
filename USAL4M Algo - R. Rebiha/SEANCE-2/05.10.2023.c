#include <stdio.h>

/* Demander l'age
Recuperer la valeur
Si 0<= Age < 13 IF (Vous êtes en enfant)
Sinon si (Age < 18) ELSE IF (Vous êtes un Ado)
Sinon si (Age < 62) ELSE IF (Vous êtes un Adulte)
Sinon ELSE (Vous êtes un Adulte) */

int main()
{
    printf("Votre Age?");
    int Age;
    scanf ("%d", &Age);
    if  ((Age > 0) && (Age < 13))
    {
        printf  ("Vous êtes en enfant");
    }    
    else if (Age < 18)
    {
        printf  ("Vous êtes un Ado");
    }
    else if (Age < 62)
    {
        printf  ("Vous êtes Adulte");
    }
    else
    {
        printf  ("Vous êtes un Senior");
    }
    
    return 0;
}

---------------------------------------------------

#include <stdio.h>

/* Demander l'age d'Alice
Donnez l'age de Bob
Comparer les Ages
Returner qui est le plus Age */

int main()
{
    printf("Donnez l'age d'Alice?\n");
    int AgeAlice;
    scanf ("%d", &AgeAlice);
    printf("Donnez l'age de Bob?\n");
    int AgeBob;
    scanf ("%d", &AgeBob);
    if  (AgeAlice > AgeBob)
    {
        printf  ("Alice est la plus Age\n");
    }    
    else
    {
        printf  ("Bob est le plus Age\n");
    }
    
    return 0;
}

---------------------------------------------------

#include <stdio.h>

int main()
{
// Boucle conteur

int conteur = 0;
while (conteur <= 10)
{
    printf("Bonjour\n");
    printf("Mon conteur:%d\n" , conteur);
    conteur = conteur+1;
}

    return 0;
}

