#include <stdio.h>

// Définir la structure Personne
struct Personne {
    char prenom[50];
    char nom[50];
    float taille;
    int age;
};

int main() {
    // Déclarer une variable de type Personne
    struct Personne personne;

    // Demander à l'utilisateur d'entrer les informations
    printf("Entrez votre prénom : Hasan ");
    scanf("%s", personne.prenom);

    printf("Entrez votre nom : Ocal ");
    scanf("%s", personne.nom);

    printf("Entrez votre taille (en mètres) : 1,67 ");
    scanf("%f", &personne.taille);

    printf("Entrez votre âge : 31 ");
    scanf("%d", &personne.age);

    // Imprimer les informations
    printf("\nInformations de la personne :\n");
    printf("Prénom : %s\n", personne.prenom);
    printf("Nom : %s\n", personne.nom);
    printf("Taille : %.2f mètres\n", personne.taille);
    printf("Âge : %d ans\n", personne.age);

    return 0;
}

-----------------------------------------------------------------------------

#include <stdio.h>

// Définir la structure Personne

struct Personne {
    char prenom[50];
    char nom[50];
    float taille;
    int age;
};

int main() {
    // Déclarer une variable de type Personne et initialiser ses champs
    struct Personne personne = {"Hasan", "Ocal", 1.67, 31};

    // Imprimer les informations à partir de la structure Personne
    printf("Informations de la personne :\n");
    printf("Prénom : %s\n", personne.prenom);
    printf("Nom : %s\n", personne.nom);
    printf("Taille : %.2f mètres\n", personne.taille);
    printf("Âge : %d ans\n", personne.age);

    return 0;
}

---------------------------------------------------------------------------------
#include <stdio.h>

//STRUCT & FONCTION

struct personne{
    char prenom[100];
    char nom[100];
    int age;
    double taille;
};

int main (){

// utiliser/appeler une variable personne
    struct personne Andres;

    printf("Donne ton age");
    scanf("%d", &Andres.age);
    printf("Donne ta taille");
    scanf("%lf", &Andres.taille);
    printf("Donne ton prenom");
    scanf("%s", Andres.nom);
    //Andres.age = 23;
    //Andres.talle = 1,69;
    printf("Bonjour j'ai %d ans et je mesure %lf metres, je m'appelle %s, %s",Andres.age,Andres.taille,Andres.prenom,Andres.nom);

    return 0;
}