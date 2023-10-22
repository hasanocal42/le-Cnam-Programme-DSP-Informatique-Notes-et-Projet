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
/// @brief 
/// @return 
int main()
{
    int cartes [52] = {1,1,1,1,2,2,2,2,3,3,3,3,4,4,4,4,5,5,5,5,6,6,6,6,7,7,7,7,8,8,8,8,9,9,9,9,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10};
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
    {
    //printf("jouer");

        if(premierTourMiser)
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
    if (sommeMainJoueur > 21) {
        printf("PERDU !!\n");
        solde = solde - mise;
    } else {
        // Comparaison des sommes de mains
        // ... (compléter cette partie)
        if (sommeMainJoueur >= sommeMainBanque || sommeMainBanque > 21) {
            printf("GAGNER !!\n");
            solde = solde + mise;
            } else 
            {
            printf("PERDU !!\n");
            solde = solde - mise;
        
            }
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

    //if(choixMenu == 3){
    //terminer = true;

    //printf("valeur premier carte: %d\n", premierCarte);
    //printf("Jouer");

    //fin while

    return 0;
}