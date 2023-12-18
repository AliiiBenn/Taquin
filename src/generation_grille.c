#include "generation_grille.h"


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



typedef struct grille {
    Cellule **tab;
    int nb_lignes;
    int nb_colonnes;

} Grille; 


typedef struct cellule {
    int valeur;
} Cellule;



Cellule *creer_cellule(int valeur) {

};


Grille *creer_grille_vide(int nb_lignes, int nb_colonnes) {

};


Grille *remplir_grille_aleatoirement(Grille *grille) {

};


Grille *charger_grille_depuis_fichier(char *nom_fichier) {

};