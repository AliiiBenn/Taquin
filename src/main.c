#include <stdio.h>
#include <stdbool.h>
#include <conio.h>
#include <time.h>
#include <stdlib.h> // Added for system("cls")

#include "../header/generation_grille.h"
#include "../header/affichage_grille.h"
#include "../header/inversion_case.h"
#include "../header/chronometre.h"
#include "../header/sauvegarde.h"


bool gererResultatInput(Grille *grille)
{
    int touche = getch();
    if (touche == 'q') inverser_case_gauche(grille);
    else if (touche == 'd') inverser_case_droite(grille);
    else if (touche == 'z') inverser_case_haut(grille);
    else if (touche == 's') inverser_case_bas(grille);
    else if (touche == ' ' || touche == 'c') return false;
    return true;
}

bool verifierVictoire(Grille *grille) {
    if (!est_grille_victoire(*grille)) {
        return false;
    }

    printf("Félicitations, vous avez gagné !\n");
    return true;

}

bool jouerTour(Grille *grille) {
    afficher_grille(*grille);

    bool running = !verifierVictoire(grille) && gererResultatInput(grille);
    return running;
}

Grille initialiserGrilleEntreeUtilisateur() {
    int nbLignes = 0;
    int nbColonnes = 0;

    bool lignesColonnesInit = (nbLignes + nbColonnes) != 0;
    bool lignesColonnesEgales = nbLignes == nbColonnes;
    bool lignesColonnesSuperieursDeux = nbLignes > 2 && nbColonnes > 2;


    while ((!lignesColonnesEgales && !lignesColonnesSuperieursDeux) || !lignesColonnesInit) {
        printf("Veuillez choisir le nombre de lignes : ");
        scanf("%d", &nbLignes);
        printf("Veuillez choisir le nombre de colonnes : ");
        scanf("%d", &nbColonnes);

        lignesColonnesInit = (nbLignes + nbColonnes) != 0;
        lignesColonnesEgales = nbLignes == nbColonnes;
        lignesColonnesSuperieursDeux = nbLignes > 2 && nbColonnes > 2;
    }
    
    return creerGrilleAleatoire(nbLignes, nbColonnes);
}

int initialiserMeilleurTemps() {
    int meilleur_temps = charger_temps_fichier("temps.txt");
    printf("Meilleur temps : ");
    afficher_chronometre(meilleur_temps);
    printf("\n");

    return meilleur_temps;
}


int main(int argc, char *argv[])
{
    Grille grille = initialiserGrilleEntreeUtilisateur();
    printf("Utiliser les touches (Z, Q, S, D) pour jouer :\n");

    int chronometre = 0;
    int meilleur_temps = initialiserMeilleurTemps();


    bool running = true;
    while (running)
    {
        afficher_chronometre(chronometre);

        int tempsAvant = time(NULL);
        running = jouerTour(&grille); 
        int tempsApres = time(NULL);
        chronometre += tempsApres - tempsAvant;
    }

    printf("Votre temps : ");
    afficher_chronometre(chronometre);
    printf("\n");
    changer_temps_fichier("temps.txt", chronometre);

    return 0;
}
