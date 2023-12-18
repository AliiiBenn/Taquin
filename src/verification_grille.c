#include <stdbool.h>
#include "generation_grille.h"

/* 

TODO: Créer la fonction qui vérifie si la grille est valide
    ? Si la grille n'est pas valide le but va être d'en générer une nouvelle tant qu'elle n'est pas valide 

TODO: Créer la fonction qui vérifie si la grille est résolue
    ? La grille est valide uniquement si pour chaque case, la précédente est inférieure à la suivante et que la dernière case est vide

*/



bool verifier_validite_grille(Grille *grille);
bool verifier_grille_resolue(Grille *grille);