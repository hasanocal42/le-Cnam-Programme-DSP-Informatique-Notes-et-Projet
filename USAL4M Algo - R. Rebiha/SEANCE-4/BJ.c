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

#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int tirerCarte(int min, int max)
{
    int resultat =(rand() % (max - min +1)) +min;
    return resultat;
}
int main()
{
    int cartes [52] = {1,1,1,1,2,2,2,2,3,3,3,3,4,4,4,4,5,5,5,5,6,6,6,6,7,7,7,7,8,8,8,8,9,9,9,9,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10};
    int solde = 1000;
    int mise = 0;
    int sommeMainJoueur = 0;
    int sommeMainBanque = 0;
    bool terminer = false;
    int choixMenu;
    bool premiereTourMiser = true;
    //int premiereCarte;
    //int deuxiemeCarte;
    int premiereCarteJoueur;
    int deuxiemeCarteJoueur;
    int carteSupplementaire;
    int tmp;
    int choixMenu;

int tirageCarte(int min, int max)
{
    int result = (rand() % (max - min + 1)) + min;
    return (result);
}

    /*
    2. Cas utilisateur
    2.1. Mise
    2.2. Tirer carte au hazard
    2.3. Annonce les cartes
    2.4. Quitter
    */

    while(!terminer)
    {
    //printf("jouer");

        if(premiereTourMiser)
        {
            printf("\nMise ?\n");
            scanf("%d", &mise);
            premiereTourMiser = false;
            tmp = tirerCarte(0,51);
            premiereCarteJoueur = cartes[tmp];
            tmp = tirerCarte(0,51);
            deuxiemeCarteJoueur = cartes[tmp];
            sommeMainJoueur = premiereCarte + deuxiemeCarte;
        }
        printf("=============================== \n");
        printf("   Solde = $%d , Mise = $%d\n", solde, mise);
        printf("===============================  \n");
        printf("  Main Initial ||      \n");
        printf("    %d et %d    ||       \n", premiereCarteJoueur, deuxiemeCarteJoueur);
        printf("=============================== \n");
        printf("  Carte supplementaire Joueur \n ");
        printf("            %d\n", carteSupplementaire);
        printf("1. Hit\n");
        printf("2. Stand\n");
        printf("3. Quit\n");

        scanf("%d", &choixMenu);
        if(choixMenu == 3)
        {
        terminer = true;
        }
        else if (choixMenu == 1)
        {
            printf("HIT !!\n");
            tmp = tirerCarte(0,51);
            carteSupplementaire = cartes[tmp];
            sommeMainJoueur = sommeMainJoueur + carteSupplementaire;

                if(sommeMainJoueur > 21)
            {
                solde = solde - mise;
                printf("Vous avez perdu ! Nouveau Solde : %d\n", solde);
                printf("Remiser ?\n");
                scanf("%d", &mise);
                tmp = tirerCarte(0,51);
                premierCarteJoueur = cartes[tmp];
                tmp = tirerCarte(0,51);
                deuxiemeCarteJoueur = cartes[tmp];
                sommeMainBanque = premiereCarteJoueur + deuxiemeCarteJoueur;
            }
        }

    }
    if (solde > 0)
    {
        printf("Congrats! You're not broke! : %d$\n", solde);
    } 
    else 
    {
        printf("Hope Your Job paids good! %d$\n", solde);
    }
    printf("Good Bye");

    //if(choixMenu == 3){
    //terminer = true;

    //printf("valeur premier carte: %d\n", premierCarte);
    //printf("Jouer");

    //fin while

    return 0;
}