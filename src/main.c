#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>


#define NB_LIGNES 4
#define NB_COLONNES 4

typedef struct grille
{
    int **tab;
    int nb_lignes;
    int nb_colonnes;
} Grille;

Grille creer_grille_vide(int ligne, int colonne)
{
    Grille grille;
    grille.nb_lignes = ligne;
    grille.nb_colonnes = colonne;
    grille.tab = (int **)malloc(ligne * sizeof(int *));
    for (int i = 0; i < ligne; i++)
    {
        grille.tab[i] = (int *)malloc(colonne * sizeof(int));
        for (int j = 0; j < colonne; j++)
        {
            grille.tab[i][j] = 0;
        }
    }
    return grille;
}

void remplir_grille_victoire(Grille *grille)
{
    int valeur = 1;
    for (int i = 0; i < grille->nb_lignes; i++)
    {
        for (int j = 0; j < grille->nb_colonnes; j++)
        {
            if (valeur == grille->nb_lignes * grille->nb_colonnes) {
                grille->tab[i][j] = -1;
            } else {
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
            if (i == grille.nb_lignes - 1 && j == grille.nb_colonnes - 1) {
                if (grille.tab[i][j] != -1) {
                    return false;
                }
            } else {
                if (grille.tab[i][j] != grille.nb_lignes * i + j + 1) {
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
            if (index == nb_cases - 1) {
                grille->tab[i][j] = -1;
            } else {
                grille->tab[i][j] = valeurs[index];
            }
            index++;
        }
    }

    free(valeurs);
    return grille;
}





#include <stdbool.h>
#include <conio.h>

bool is_arrow_up_pressed()
{
    if (_kbhit())
    {
        int key = _getch();
        if (key == 224 || key == 0)
        {
            key = _getch();
            return key == 72;
        }
    }
    return false;
}

bool is_arrow_down_pressed()
{
    if (_kbhit())
    {
        int key = _getch();
        if (key == 224 || key == 0)
        {
            key = _getch();
            return key == 80;
        }
    }
    return false;
}

bool is_arrow_left_pressed()
{
    if (_kbhit())
    {
        int key = _getch();
        if (key == 224 || key == 0)
        {
            key = _getch();
            return key == 75;
        }
    }
    return false;
}

bool is_arrow_right_pressed()
{
    if (_kbhit())
    {
        int key = _getch();
        if (key == 224 || key == 0)
        {
            key = _getch();
            return key == 77;
        }
    }
    return false;
}


void inverser_case_gauche(Grille* grille)
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

void inverser_case_droite(Grille* grille)
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

void inverser_case_haut(Grille* grille)
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

void inverser_case_bas(Grille* grille)
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
            if (grille.tab[i][j] == -1) {
                printf("    |");
            } else {
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

int main(int argc, char *argv[]) {
    printf("Entree dans le programme.\n");

    
    Grille grille = creer_grille_vide(NB_LIGNES, NB_COLONNES);
    remplir_grille_victoire(&grille);
    inverser_case_haut(&grille);

    afficher_grille(grille);
    printf("\n");


    while (true) {
        char touche = getch();
        if (touche == 'q')
        {
            inverser_case_gauche(&grille);
        }
        else if (touche == 'd')
        {
            inverser_case_droite(&grille);
        }
        else if (touche == 'z')
        {
            inverser_case_haut(&grille);
        }
        else if (touche == 's')
        {
            inverser_case_bas(&grille);
        }

        afficher_grille(grille);
        printf("\n");

        if (est_grille_victoire(grille)) {
            printf("Felicitations, vous avez gagne !\n");
            break;
        }
    }
    

    return 0;
}
