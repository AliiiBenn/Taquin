
#include <stdio.h> 
#include <stdbool.h>

#include "../header/generation_grille.h"


void inverser_case_gauche(Grille *grille)
{
    for (int i = 0; i < grille->nb_lignes; i++)
    {
        for (int j = 0; j < grille->nb_colonnes; j++)
        {
            if (grille->tab[i][j] == -1 && j > 0)
            {
                int temp = grille->tab[i][j];
                grille->tab[i][j] = grille->tab[i][j - 1];
                grille->tab[i][j - 1] = temp;
                return;
            }
        }
    }
}

void inverser_case_droite(Grille *grille)
{
    for (int i = 0; i < grille->nb_lignes; i++)
    {
        for (int j = 0; j < grille->nb_colonnes; j++)
        {
            if (grille->tab[i][j] == -1 && j < grille->nb_colonnes - 1)
            {
                int temp = grille->tab[i][j];
                grille->tab[i][j] = grille->tab[i][j + 1];
                grille->tab[i][j + 1] = temp;
                return;
            }
        }
    }
}

void inverser_case_haut(Grille *grille)
{
    for (int i = 0; i < grille->nb_lignes; i++)
    {
        for (int j = 0; j < grille->nb_colonnes; j++)
        {
            if (grille->tab[i][j] == -1 && i > 0)
            {
                int temp = grille->tab[i][j];
                grille->tab[i][j] = grille->tab[i - 1][j];
                grille->tab[i - 1][j] = temp;
                return;
            }
        }
    }
}

void inverser_case_bas(Grille *grille)
{
    for (int i = 0; i < grille->nb_lignes; i++)
    {
        for (int j = 0; j < grille->nb_colonnes; j++)
        {
            if (grille->tab[i][j] == -1 && i < grille->nb_lignes - 1)
            {
                int temp = grille->tab[i][j];
                grille->tab[i][j] = grille->tab[i + 1][j];
                grille->tab[i + 1][j] = temp;
                return;
            }
        }
    }
}

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
