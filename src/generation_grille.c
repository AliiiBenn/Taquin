#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>

#include "../header/grille.h"
#include "../header/inversion_case.h"


/**
 * Crée une grille avec le nombre de lignes et de colonnes spécifié.
 * 
 * @param ligne Le nombre de lignes de la grille.
 * @param colonne Le nombre de colonnes de la grille.
 * @return La grille créée.
 */
Grille creerGrille(int ligne, int colonne) {
    Grille grille;
    grille.nb_lignes = ligne;
    grille.nb_colonnes = colonne;
    grille.tab = (int **)malloc(ligne * sizeof(int *));
    
    for (int i = 0; i < ligne; i++) {
        grille.tab[i] = (int *)malloc(colonne * sizeof(int));
    }
    
    return grille;
}

/**
 * Crée une grille remplie de zéros avec le nombre de lignes et de colonnes spécifié.
 * 
 * @param ligne Le nombre de lignes de la grille.
 * @param colonne Le nombre de colonnes de la grille.
 * @return La grille remplie de zéros.
 */
Grille creerGrilleZeros(int ligne, int colonne)
{
    Grille grille = creerGrille(ligne, colonne);

    for (int i = 0; i < ligne; i++)
    {
        int *ligneCourante = grille.tab[i];
        for (int j = 0; j < colonne; j++)
        {
            ligneCourante[j] = 0;
        }
    }

    return grille;
}

/**
 * Crée une grille de victoire avec les dimensions spécifiées.
 *
 * @param ligne Le nombre de lignes de la grille.
 * @param colonne Le nombre de colonnes de la grille.
 * @return La grille de victoire créée.
 */
Grille creerGrilleVictoire(int ligne, int colonne)
{
    Grille grille = creerGrille(ligne, colonne);

    int valeur = 1;
    for (int i = 0; i < ligne; i++)
    {
        for (int j = 0; j < colonne; j++)
        {
            if (valeur == ligne * colonne)
            {
                grille.tab[i][j] = -1;
            }
            else
            {
                grille.tab[i][j] = valeur;
            }
            valeur++;
        }
    }

    return grille;
}

/**
 * Vérifie si la grille spécifiée est une grille de victoire.
 *
 * @param grille La grille à vérifier.
 * @return true si la grille est une grille de victoire, sinon false.
 */
bool est_grille_victoire(Grille grille)
{
    for (int i = 0; i < grille.nb_lignes; i++)
    {
        for (int j = 0; j < grille.nb_colonnes; j++)
        {
            if (grille.tab[i][j] != grille.nb_lignes * i + j + 1)
            {
                if (grille.tab[i][j] == -1)
                {
                    continue;
                }
                else
                {
                    return false;
                }
            }
        }
    }
    return true;
}


/**
 * Crée une grille aléatoire avec le nombre de lignes et de colonnes spécifié.
 * 
 * @param ligne Le nombre de lignes de la grille.
 * @param colonne Le nombre de colonnes de la grille.
 * @return La grille aléatoire créée.
 */
Grille creerGrilleAleatoire(int ligne, int colonne)
{
    Grille grille = creerGrilleVictoire(ligne, colonne);
    int nb_inversions = rand() % (ligne * colonne * 10);

    for (int i = 0; i < nb_inversions; i++)
    {
        int random = rand() % 4;
        switch (random)
        {
            case 0:
                inverser_case_gauche(&grille);
                break;
            case 1:
                inverser_case_droite(&grille);
                break;
            case 2:
                inverser_case_haut(&grille);
                break;
            case 3:
                inverser_case_bas(&grille);
                break;
        }
    }

    return grille;
}


/**
 * Crée une grille à partir d'un fichier.
 * 
 * @param nomFichier Le nom du fichier contenant les valeurs de la grille.
 * @param ligne Le nombre de lignes de la grille.
 * @param colonne Le nombre de colonnes de la grille.
 * @return La grille créée à partir du fichier.
 */
Grille creerGrilleDepuisFichier(char * nomFichier, int ligne, int colonne) {
    Grille grille = creerGrille(ligne, colonne);
    FILE *fichier = fopen(nomFichier, "r");

    if (fichier == NULL) {
        printf("Erreur lors de l'ouverture du fichier.\n");
        return grille;
    }

    for (int i = 0; i < ligne; i++) {
        for (int j = 0; j < colonne; j++) {
            int valeur;
            fscanf(fichier, "%d", &valeur);
            grille.tab[i][j] = valeur;
        }
    }

    fclose(fichier);
    return grille;
}
