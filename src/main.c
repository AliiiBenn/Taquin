#include <stdio.h>
#include <stdbool.h>
#include <conio.h>

#include "../header/generation_grille.h"
#include "../header/affichage_grille.h"
#include "../header/inversion_case.h"


bool gererResultatInput(Grille *grille, int touche) {
    if (touche == 'q')
    {
        inverser_case_gauche(grille);
    }
    else if (touche == 'd')
    {
        inverser_case_droite(grille);
    }
    else if (touche == 'z')
    {
        inverser_case_haut(grille);
    }
    else if (touche == 's')
    {
        inverser_case_bas(grille);
    }
    else if (touche == ' ' || touche == 'c')
    {
        return false;
    }
    return true;
}


bool jouer_tour(Grille* grille) {
    afficher_grille(*grille);
    printf("\n");

    if (est_grille_victoire(*grille)) {
        printf("Félicitations, vous avez gagné !\n");
        return false;
    } else {
        printf("On continue !\n\n");
    }

    int touche = getch();
    bool running = gererResultatInput(grille, touche);

    return running;

}

int main(int argc, char *argv[]) {
    printf("Utiliser les touches (Z, Q, S, D) pour jouer :\n");
    Grille grille = creerGrilleDepuisFichier("grilles/grille.txt", NB_LIGNES, NB_COLONNES);

    bool running = true;
    while (running) {
        running = jouer_tour(&grille);
    }

    return 0;
}
