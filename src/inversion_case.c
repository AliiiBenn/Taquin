#include "../header/grille.h"


void inverser_case(Grille *grille, int di, int dj)
{
    for (int i = 0; i < grille->nb_lignes; i++)
    {
        for (int j = 0; j < grille->nb_colonnes; j++)
        {
            if (grille->tab[i][j] == -1 && i + di >= 0 && i + di < grille->nb_lignes && j + dj >= 0 && j + dj < grille->nb_colonnes)
            {
                int temp = grille->tab[i][j];
                grille->tab[i][j] = grille->tab[i + di][j + dj];
                grille->tab[i + di][j + dj] = temp;
                return;
            }
        }
    }
}

void inverser_case_gauche(Grille *grille)
{
    inverser_case(grille, 0, -1);
}

void inverser_case_droite(Grille *grille)
{
    inverser_case(grille, 0, 1);
}

void inverser_case_haut(Grille *grille)
{
    inverser_case(grille, -1, 0);
}

void inverser_case_bas(Grille *grille)
{
    inverser_case(grille, 1, 0);
}