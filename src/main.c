#include <stdio.h>
#include <stdbool.h>
#include <curses.h>
#include "../header/generation_grille.h"
#include "../header/affichage_grille.h"

int main(int argc, char *argv[]) {
    initscr();
    cbreak(); 
    noecho(); 
    keypad(stdscr, TRUE); 

    printw("Utiliser les touches (Z, Q, S, D) pour jouer :\n");
    Grille grille = creerGrille(NB_LIGNES, NB_COLONNES);
    remplirGrilleAvecZeros(grille);

    remplir_grille_victoire(&grille);
    inverser_case_haut(&grille);

    // while (!est_grille_soluble(&grille)) {
    //     remplirGrilleAvecZeros(grille);
    //     remplir_grille_aleatoirement(&grille);
    // }

    afficher_grille(grille);
    printw("\n");

    int touche;

    while (true) {
        touche = getch();

        if (touche == 'q') {
            inverser_case_gauche(&grille);
        } else if (touche == 'd') {
            inverser_case_droite(&grille);
        } else if (touche == 'z') {
            inverser_case_haut(&grille);
        } else if (touche == 's') {
            inverser_case_bas(&grille);
        } else if (touche == ' ') {
            break;
        }

        clear();
        afficher_grille(grille);
        printw("\n");

        if (est_grille_victoire(grille)) {
            printw("Félicitations, vous avez gagné !\n");
            break;
        } else {
            printw("On continue !\n\n");
        }
        refresh(); // Rafraîchir l'affichage
    }


    return 0;
}
