/*
1. Donne
    1.1. Tableau de valeur des cartes
    1.2. Solde
    1.3. Mise
    1.4. Carte joueurs et de la banques
    1.5. Boolean qui dit si c'est terminé ou pas

2. Cas utilisateur
    2.1. Mise
    2.2. Tirer carte au hazard
    2.3. Annonce les cartes
    2.4. Quitter
*/
//Ces commentaires décrivent les différentes variables et éléments utilisés dans le programme.

#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int tirerCarte(int min, int max)
{
    int resultat =(rand() % (max - min +1)) +min;
    return resultat;
    //La fonction tirerCarte génère un nombre aléatoire entre min et max inclus.
}
int main()
{
    int cartes [52] = {1,1,1,1,2,2,2,2,3,3,3,3,4,4,4,4,5,5,5,5,6,6,6,6,7,7,7,7,8,8,8,8,9,9,9,9,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10};
    //Un tableau cartes est initialisé avec les valeurs des cartes. Chaque nombre représente la valeur d'une carte (de 1 à 10).
    int solde = 1000;
    int mise = 0;
    int sommeMainJoueur = 0;
    int sommeMainBanque = 0;
    bool terminer = false;
    int choixMenu;
    bool premierTourMiser = true;
    //int premiereCarte;
    //int deuxiemeCarte;
    int premiereCarteJoueur;
    int deuxiemeCarteJoueur;
    int premiereCarteBanque;
    int deuxiemeCarteBanque;
    int carteSupplementaire;
    int tmp;
    //Ces lignes définissent différentes variables utilisées dans le jeu. Par exemple, solde représente l'argent du joueur, mise est la mise actuelle, etc.

    // int tirageCarte(int min, int max){
    //int result = (rand() % (max - min + 1)) + min;
    //return (result); }

    /*
    2. Cas utilisateur
    2.1. Mise
    2.2. Tirer carte au hazard
    2.3. Annonce les cartes
    2.4. Quitter
    */

    while(!terminer)
    //C'est une boucle qui continuera tant que la variable terminer est fausse.
    {
    //printf("jouer");

        if(premierTourMiser)
        //Cela vérifie si c'est le premier tour et si c'est le cas, demande au joueur de faire une mise.
        {
            printf("\nMise ?\n");
            scanf("%d", &mise);
            premierTourMiser = false;
            tmp = tirerCarte(0,51);
            premiereCarteJoueur = cartes[tmp];
            tmp = tirerCarte(0,51);
            deuxiemeCarteJoueur = cartes[tmp];
            sommeMainJoueur = premiereCarteJoueur + deuxiemeCarteJoueur;
            }
            printf("=============================== \n");
            printf("   Solde = $%d , Mise = $%d\n", solde, mise);
            //Ces lignes affichent l'état actuel du jeu, y compris le solde et la mise.
            printf("===============================  \n");
            printf("  Main Initial ||      \n");
            printf("    %d et %d    ||       \n", premiereCarteJoueur, deuxiemeCarteJoueur);
            printf("=============================== \n");
            printf("  Somme de la main courante %d  || \n", sommeMainJoueur);
            printf("  ======================\n");
            printf("1. Hit/Carte Supplementaire\n");
            printf("2. Stand/J'arrete\n");
            printf("3. Quit/Je sort du jeu\n");

            scanf("%d", &choixMenu);
            //Le programme attend que le joueur entre un choix (1, 2 ou 3) et le stocke dans la variable choixMenu.

            if(choixMenu == 3)
            //Si le joueur choisit 3, le jeu se termine.
            {
            terminer = true;
            }

            else if (choixMenu == 1)
            //Si le joueur choisit 1, il tire une carte supplémentaire.
            {
            printf("HIT !!\n");
            tmp = tirerCarte(0,51);
            carteSupplementaire = cartes[tmp];
            sommeMainJoueur = sommeMainJoueur + carteSupplementaire;

                if(sommeMainJoueur > 21)
                {
                    solde = solde - mise;
                    printf("Vous avez perdu!, Nouveau Solde: %d\n", solde);
                    printf("reMiser ?\n");
                    scanf("%d", &mise);
                    tmp = tirerCarte(0,51);
                    premiereCarteJoueur = cartes[tmp];
                    tmp = tirerCarte(0,51);
                    deuxiemeCarteJoueur = cartes[tmp];
                    sommeMainJoueur = premiereCarteJoueur + deuxiemeCarteJoueur;
                    }
                    else if (choixMenu == 2)
                    //Si le joueur choisit 2, il arrête de tirer des cartes supplémentaires.
                    {
                        printf("HIT !!\n");
                        tmp = tirerCarte(0,51);
                        carteSupplementaire = cartes[tmp];
                        sommeMainBanque = sommeMainBanque + carteSupplementaire;

                if(sommeMainBanque > 21)
                {
                    solde = solde - mise;
                    printf("Vous avez perdu!, Nouveau Solde: %d\n", solde);
                    printf("reMiser ?\n");
                    scanf("%d", &mise);
                    tmp = tirerCarte(0,51);
                    premiereCarteBanque = cartes[tmp];
                    tmp = tirerCarte(0,51);
                    deuxiemeCarteBanque = cartes[tmp];
                    sommeMainBanque = premiereCarteBanque + deuxiemeCarteBanque;
                    }
                }
            }
            else if (choixMenu == 2)
            {
                printf("STAND !!\n");
                // SI sommecourante > 21 alors perdu: solde = solde - mise
                    if(sommeMainJoueur > 21){
                    printf("PERDU !!\n");
                    solde = solde - mise;
                    printf("\n reMiser ?\n");
                    scanf("%d", &mise);
                    tmp = tirerCarte(0,51);
                    premiereCarteJoueur = cartes[tmp];
                    tmp = tirerCarte(0,51);
                    deuxiemeCarteJoueur = cartes[tmp];
                    sommeMainJoueur = premiereCarteJoueur + deuxiemeCarteJoueur;
                }
                else
                {
                    printf("GAGNER !!\n");
                    solde = solde + mise;
                    printf("\n reMiser ?\n");
                    scanf("%d", &mise);
                    tmp = tirerCarte(0,51);
                    premiereCarteJoueur = cartes[tmp];
                    tmp = tirerCarte(0,51);
                    deuxiemeCarteJoueur = cartes[tmp];
                    sommeMainJoueur = premiereCarteJoueur + deuxiemeCarteJoueur;
                }
            }
        }

    //fin while
    //if (solde > 0){
    //printf("Congrats! You're not broke! : %d$\n", solde);} 
    //else {
    //printf("Hope Your Job paids good! %d$\n", solde);}
    printf("Good Bye");
    //Ces lignes commentées semblent être des commentaires inutilisés ou des parties du code qui ont été désactivées.


    //if(choixMenu == 3){
    //terminer = true;

    //printf("valeur premier carte: %d\n", premierCarte);
    //printf("Jouer");

    //fin while

    return 0;
    //Le programme se termine et renvoie 0 pour indiquer qu'il s'est terminé correctement.
}