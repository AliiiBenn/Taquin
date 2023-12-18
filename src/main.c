#include <stdio.h>
#include <stdbool.h>
#include <conio.h>




#include "../header/generation_grille.h"
#include "../header/affichage_grille.h"


int main(int argc, char *argv[]) {
    printf("Entree dans le programme.\n");

    
    Grille grille = creerGrille(NB_LIGNES, NB_COLONNES);
    remplirGrilleAvecZeros(grille);

    remplir_grille_aleatoirement(&grille);

    while (!est_grille_soluble(&grille))
    {
        remplirGrilleAvecZeros(grille);
        remplir_grille_aleatoirement(&grille);
    }

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
