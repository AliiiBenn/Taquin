#include <stdio.h>
#include <stdlib.h>

// Création de booléen
#define True 1
#define False 0

// Fonction pour vérifier si la grille initial est correct ou non.
int verification_init() {

}

// Fonction pour vérifier si la grille a été résolue ou non.
int verification_final(int **tab, int n) {
    for(int i = 0; i<n; i++) { // Boucle pour parcourir les éléments de la première ligne de la matrice.
        if(tab[i][0] != i+1) { // Condition pour que la résolution soit erronée. Si les éléments de la première ligne sont différents de i+1.
            return False; // La fonction retourne False si l'un des éléments de la première ligne n'est pas dons son emplacement initial.
        }
        for(int j = 1; j<n; j++) { // Boucle pour parcourir les éléments restants sans la première ligne.
            if (tab[i][j] != (tab[i][j-1]+n)) { // Condition pour que la résolution soit erronée. Si les éléments sont différents des éléments de la ligne précédente + n.
                return False; // La fonction retourne False si l'un des éléments n'est pas dans son emplacement initial.
            }
        }
    }
    return True; // La fonction retourne True si elle n'a pas été quitté. Ce qui veux dire que tout les éléments de la matrice sont à leurs places initial. Et donc que la résolution est vérifiée.
}

int main() {
    int **tab = (int **)malloc(2*sizeof(int *));
    for(int i=0; i<2; i++) {
        tab[i] = (int *)malloc(2*sizeof(int));
    }

    tab[0][0] = 1;
    tab[1][0] = 2;
    tab[0][1] = 3;
    tab[1][1] = 4;

    int etat = verification_final(tab, 2);
    if (etat == True) {
        printf("Ok\n");
    }
    else {
        printf("Error\n");
    }
    
    
    for(int j=0; j<2; j++) {
        free(tab[j]);
    }
    free(tab);

    return 0;
}