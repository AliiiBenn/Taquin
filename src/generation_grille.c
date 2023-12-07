#include "..\header\generation_grille.h"



typedef struct grille {
    Cellule **tab;
    int nb_lignes;
    int nb_colonnes;

} Grille; 


typedef struct cellule {
    int valeur;
} Cellule;

// Fonction pour créer les cellules et donner une valeur à chaque cellules.
Cellule *creer_cellule(int valeur) {
    Cellule cellule;
    cellule.valeur = valeur;
    return cellule.valeur;
}

// Fonction pour céer une grille vide et retourner la grille.
Grille *creer_grille_vide(int ligne, int colonne) {
    Grille grille;
    grille.nb_lignes = ligne;
    grille.nb_colonnes = colonne;
    return grille.tab;
}

// Fonction pour remplir automatiquement la grille avec des valeurs aléatoires.
// Je n'ai pas encore tester cette fonction.
Grille *remplir_grille_aleatoirement(Grille *grille) {
    int **tab_intermediaire = creer_grille_vide(grille->nb_lignes, grille->nb_colonnes); // Création d'une grille intermédiaire pour le mélange.
    int **tab = grille->tab; // Récupération de la grille.

    int ligne = 0;
    int colonne = 0;
    int indice = NB_CELLULES;

    for(int i = 0; i < NB_LIGNES + 1; i++) {
        tab[i][0] = i; // Remplissage des cellules des grilles avec des valeurs. 
        tab[0][i] = i; // Pas encore fonctionnelle et pas encore testé.
    }
    for(int i = 0; i < NB_LIGNES; i++){
        for (int j = 0; j < NB_COLONNES; j++) {
            ligne = rand() % (NB_LIGNES - indice); // Récupération d'une valeur aléatoire.
            colonne = rand() % (NB_COLONNES - indice); // Récup^ération d'une valeur aléatoire.
            tab_intermediaire[i][j] = tab[ligne][colonne]; // Affectaion des valeurs dans la grille intermédiaire.
        }
    }
}

Grille * charger_grille_depuis_fichier(char *nom_fichier);