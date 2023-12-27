
#define NB_LIGNES 4
#define NB_COLONNES 4

#ifndef GENERATION_GRILLE_H
#define GENERATION_GRILLE_H

#include <stdbool.h>
#include "grille.h"


// typedef struct grille
// {
//     int **tab;
//     int nb_lignes;
//     int nb_colonnes;
// } Grille;

Grille creerGrille(int ligne, int colonne);
Grille creerGrilleZeros(int ligne, int colonne);
Grille creerGrilleVictoire(int ligne, int colonne);
bool est_grille_victoire(Grille grille);
Grille creerGrilleAleatoire(int ligne, int colonne);
Grille *charger_grille_depuis_fichier(char *nom_fichier);
bool est_grille_soluble(Grille *grille);


#endif