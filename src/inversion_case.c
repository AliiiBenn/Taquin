#include "../header/grille.h"


/**
 * Inverse la case vide avec la case adjacente spécifiée par les décalages di et dj dans la grille.
 * 
 * @param grille Un pointeur vers la grille de jeu.
 * @param di     Le décalage vertical de la case adjacente.
 * @param dj     Le décalage horizontal de la case adjacente.
 */
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

/**
 * Inverse la case à gauche de la position actuelle dans la grille.
 * 
 * @param grille La grille de jeu.
 */
void inverser_case_gauche(Grille *grille)
{
    inverser_case(grille, 0, -1);
}

/**
 * Inverse la case à droite de la position actuelle dans la grille.
 * 
 * @param grille La grille de jeu.
 */
void inverser_case_droite(Grille *grille)
{
    inverser_case(grille, 0, 1);
}

/**
 * Inverse la case en haut de la position actuelle dans la grille.
 * 
 * @param grille La grille de jeu.
 */
void inverser_case_haut(Grille *grille)
{
    inverser_case(grille, -1, 0);
}

/**
 * Inverse la case en bas de la position actuelle dans la grille.
 * 
 * @param grille La grille de jeu.
 */
void inverser_case_bas(Grille *grille)
{
    inverser_case(grille, 1, 0);
}