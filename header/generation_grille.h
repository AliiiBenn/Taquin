


extern const int NB_LIGNES = 4;
extern const int NB_COLONNES = 4;

extern const int NB_CELLULES = (NB_LIGNES * NB_COLONNES) - 1;


typedef struct cellule {
    int valeur;
} Cellule; 


typedef struct grille {
    Cellule **tab;
    int nb_lignes;
    int nb_colonnes;
} Grille;



Cellule *creer_cellule(int valeur);
Grille *creer_grille_vide(int nb_lignes, int nb_colonnes);

Grille *remplir_grille_aleatoirement(Grille *grille);
Grille *charger_grille_depuis_fichier(char *nom_fichier);