#include <stdio.h>
#include <stdlib.h>

// Fonction pour afficher la grille sur le terminal.
void afficher_grille(int **tab, int taille) {
    for (int i=0; i<taille; i++) {
        printf("|"); // Affichage d'une barre verticale pour la délimitation à l'intérieur et à l'exterieur de la grille.
        for (int j=0; j<taille; j++) {
            printf("%d|", tab[i][j]); // Affichage des éléments de la grille suivi de l'affichage d'une barre verticale pour la délimatation à l'interieur et à l'extérieur de la grille.
            if (j==taille-1) { // Condition pour détecter le dernier élément de la ligne.
                printf("\n"); // Saut de ligne pour un affichage conforme au jeu de taquin.
            }
        }
    }
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

    afficher_grille(tab, n);

    for (int j=0; j<n; j++) {
        free(tab[j]);
    }
    free(tab);

    return 0;
}