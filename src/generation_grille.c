#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>


/*

TODO: Créer la fonction qui créer dynamiquement une cellule
    ? Le but de cette fonction va être de créer une cellule avec la valeur passée en paramètre


TODO: Créer la fonction qui créer dynamiquement une grille vide
    ? Le but de cette fonction va être de créer une grille vide avec le nombre de lignes et de colonnes passées en paramètre. Chaque case de la grille doit être initialisée à une cellule ayant pour valeur 0


TODO: Créer la fonction qui remplie une grille aléatoirement
    ? Le but de cette fonction va être de remplir une grille aléatoirement avec des valeurs allant de 1 à 15. La dernière case doit être vide. Il ne doit pas y avoir de répétition de valeurs dans la grille


TODO: Créer la fonction qui charge une grille depuis un fichier
    ? Le but de cette fonction va être de charger une grille depuis un fichier. Le fichier doit contenir le nombre de lignes et de colonnes de la grille sur la première ligne. Ensuite, chaque ligne doit contenir les valeurs de chaque cellule séparées par un espace. La dernière case doit être vide. Il ne doit pas y avoir de répétition de valeurs dans la grille

*/



typedef struct grille
{
    int **tab;
    int nb_lignes;
    int nb_colonnes;
} Grille;


Grille creerGrille(int ligne, int colonne) {
    Grille grille;
    grille.nb_lignes = ligne;
    grille.nb_colonnes = colonne;
    grille.tab = (int **)malloc(ligne * sizeof(int *));
    
    return grille;
}

void remplirGrilleAvecZeros(Grille grille)
{
    int lignes = grille.nb_lignes;
    int colonnes = grille.nb_colonnes;
    int **tab = grille.tab;

    for (int i = 0; i < lignes; i++)
    {
        tab[i] = (int *)malloc(colonnes * sizeof(int));
        for (int j = 0; j < colonnes; j++)
        {
            grille.tab[i][j] = 0;
        }
    }
}

void remplir_grille_victoire(Grille *grille)
{
    int valeur = 1;
    for (int i = 0; i < grille->nb_lignes; i++)
    {
        for (int j = 0; j < grille->nb_colonnes; j++)
        {
            if (valeur == grille->nb_lignes * grille->nb_colonnes)
            {
                grille->tab[i][j] = -1;
            }
            else
            {
                grille->tab[i][j] = valeur;
            }
            valeur++;
        }
    }
}

bool est_grille_victoire(Grille grille)
{
    for (int i = 0; i < grille.nb_lignes; i++)
    {
        for (int j = 0; j < grille.nb_colonnes; j++)
        {
            if (i == grille.nb_lignes - 1 && j == grille.nb_colonnes - 1)
            {
                if (grille.tab[i][j] != -1)
                {
                    return false;
                }
            }
            else
            {
                if (grille.tab[i][j] != grille.nb_lignes * i + j + 1)
                {
                    return false;
                }
            }
        }
    }
    return true;
}

Grille *remplir_grille_aleatoirement(Grille *grille)
{
    // Initialisation du générateur de nombres aléatoires
    srand(time(NULL));

    int nb_cases = grille->nb_lignes * grille->nb_colonnes;
    int *valeurs = (int *)malloc(nb_cases * sizeof(int));

    // Remplissage du tableau de valeurs uniques
    for (int i = 0; i < nb_cases; i++)
    {
        valeurs[i] = i + 1;
    }

    // Mélange des valeurs
    for (int i = 0; i < nb_cases - 1; i++)
    {
        int j = i + rand() % (nb_cases - i);
        int temp = valeurs[i];
        valeurs[i] = valeurs[j];
        valeurs[j] = temp;
    }

    // Remplissage de la grille avec les valeurs aléatoires
    int index = 0;
    for (int i = 0; i < grille->nb_lignes; i++)
    {
        for (int j = 0; j < grille->nb_colonnes; j++)
        {
            if (index == nb_cases - 1)
            {
                grille->tab[i][j] = -1;
            }
            else
            {
                grille->tab[i][j] = valeurs[index];
            }
            index++;
        }
    }

    free(valeurs);
    return grille;
}
