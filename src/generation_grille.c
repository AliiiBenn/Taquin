#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>


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
        tab[i] = calloc(colonnes, sizeof(int));
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

void melanger_valeurs(int *valeurs, int nb_cases)
{
    for (int i = 0; i < nb_cases - 1; i++)
    {
        int j = i + rand() % (nb_cases - i);
        int temp = valeurs[i];
        valeurs[i] = valeurs[j];
        valeurs[j] = temp;
    }
}

void remplir_grille_valeurs(Grille *grille, int *valeurs, int nb_cases)
{
    int index = 0;
    for (int i = 0; i < grille->nb_lignes; i++)
    {
        for (int j = 0; j < grille->nb_colonnes; j++)
        {
            grille->tab[i][j] = (index == nb_cases - 1) ? -1 : valeurs[index];
            index++;
        }
    }
}

void remplir_grille_aleatoirement(Grille *grille)
{
    srand(time(NULL));

    int nb_cases = grille->nb_lignes * grille->nb_colonnes;
    int *valeurs = (int *)malloc(nb_cases * sizeof(int));

    for (int i = 0; i < nb_cases; i++)
    {
        valeurs[i] = i + 1;
    }

    melanger_valeurs(valeurs, nb_cases);

    remplir_grille_valeurs(grille, valeurs, nb_cases);

    free(valeurs);
}


bool est_grille_soluble(Grille *grille)
{
    int inversion_count = 0;
    int blank_row = 0;
    int blank_col = 0;

    for (int i = 0; i < grille->nb_lignes; i++) {
        for (int j = 0; j < grille->nb_colonnes; j++) {
            int current_value = grille->tab[i][j];

            // Ignorer la case vide
            if (current_value == 0) {
                blank_row = i;
                blank_col = j;
                continue;
            }

            for (int x = i; x < grille->nb_lignes; x++)
            {
                for (int y = (x == i) ? j + 1 : 0; y < grille->nb_colonnes; y++)
                {
                    int next_value = grille->tab[x][y];
                    if (next_value != 0 && current_value > next_value) {
                        inversion_count++;
                    }
                }
            }
        }
    }

    bool is_permutation_even = (inversion_count % 2 == 0);
    bool is_blank_even = ((grille->nb_lignes - blank_row) % 2 == 0);

    return (is_permutation_even == is_blank_even);
}