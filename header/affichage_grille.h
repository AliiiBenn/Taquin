#ifndef AFFICHAGE_GRILLE_H
#define AFFICHAGE_GRILLE_H

#include <stdbool.h>
#include "generation_grille.h"

void inverser_case_gauche(Grille *grille);
void inverser_case_droite(Grille *grille);
void inverser_case_haut(Grille *grille);
void inverser_case_bas(Grille *grille);
void afficher_grille(Grille grille);

#endif
