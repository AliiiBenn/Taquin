
#define NB_LIGNES 4
#define NB_COLONNES 4

#ifndef GENERATION_GRILLE_H
#define GENERATION_GRILLE_H

#include <stdbool.h>

typedef struct grille
{
    int **tab;
    int nb_lignes;
    int nb_colonnes;
} Grille;

Grille creerGrille(int ligne, int colonne);
void remplirGrilleAvecZeros(Grille grille);
void remplir_grille_victoire(Grille *grille);
bool est_grille_victoire(Grille grille);
Grille *remplir_grille_aleatoirement(Grille *grille);
Grille *charger_grille_depuis_fichier(char *nom_fichier);

#endif // GENERATION_GRILLE_H