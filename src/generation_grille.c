#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>

#include "../header/grille.h"
#include "../header/inversion_case.h"


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
