
#include <stdio.h> 
#include <stdbool.h>

#include "../header/generation_grille.h"





void afficher_grille(Grille grille)
{
    for (int i = 0; i < grille.nb_lignes; i++)
    {
        printf("|");
        for (int j = 0; j < grille.nb_colonnes; j++)
        {
            if (grille.tab[i][j] == -1)
            {
                printf("    |");
            }
            else
            {
                printf("%3d |", grille.tab[i][j]);
            }

            bool finLigne = (j == grille.nb_colonnes - 1);
            if (finLigne)
            {
                printf("\n");
            }
        }
    }
}
