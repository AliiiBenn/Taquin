#include <stdio.h>
#include <stdlib.h>

// Création de booléen
#define True 1
#define False 0

// Fonction pour vérifier si la grille initial est correct ou non.
int verifier_validite_grille() {
    return 0;
}

// Fonction pour vérifier si la grille a été résolue ou non.
int verifier_grille_resolue(int **tab, int taille) {
    for(int i = 0; i<taille; i++) { 
        for(int j = 0; j<taille; j++) { 
            if (i==0 && (tab[i][j] != j+1)) { // Condition pour savoir si les éléments de la première ligne sont dans l'ordre croissant ou non (à partir de l'indice + 1).
                return False; // La fonction renvoie False si l'un des éléments de la première ligne n'est pas à son emplacement initial.
            }
            else if (i!=0 && (tab[i][j] != tab[i-1][j]+taille)) { // Condition pour savoir si le reste des éléments est l'ordre croissants (à partir de l'élément précédent + la taille de la grille). 
                return False; // La fonction renvoie False si l'un des éléments de la grille n'est pas à son emplacement initial.
            }
        }
    }
    return True; // La fonction retourne True si elle n'a pas été quitté. Ce qui veux dire que tout les éléments de la matrice sont à leurs places initial. Et donc que la résolution est vérifiée.
}

// La fonction main n'est présente que pour des tests et ne sera pas présente dans la verrsion finale.
int main() {
    // Il faudrait essayer d'utiliser : Grille grille;
    // Pour ensuite bien définire tab : int **tab = grille.tab;
    // Et l'utiliser comme si on avait utilisé malloc.

    int n = 3;
    int **tab = (int **)malloc(n * sizeof(int *));
	for (int i=0; i<n; i++) {
		tab[i] = (int *)malloc(n * sizeof(int));
	}
    tab[0][0] = 1; tab[0][1] = 2; tab[0][2] = 3;
    tab[1][0] = 4; tab[1][1] = 5; tab[1][2] = 6;
    tab[2][0] = 7; tab[2][1] = 8; tab[2][2] = 9;

    int etat = verifier_grille_resolue(tab, n);
    if (etat == True) {
        printf("Ok\n");
    }
    else {
        printf("No\n");
    }

    for (int j=0; j<n; j++) {
        free(tab[j]);
    }
    free(tab);
    return 0;
}