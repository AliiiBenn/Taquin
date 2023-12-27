#include <stdio.h>
#include <stdbool.h>

#define MINUTE 60
#define HEURE (MINUTE * 60)


/**
 * Affiche le chronomètre avec le temps donné en paramètre.
 *
 * @param temps Le temps en secondes à afficher.
 */
void afficher_chronometre(int temps)
{
    int heures = temps / HEURE;
    int minutes = (temps % HEURE) / MINUTE;
    int secondes = temps % MINUTE;

    printf("%02d:%02d:%02d", heures, minutes, secondes);
}


/**
 * Enregistre le temps dans un fichier.
 *
 * Cette fonction ouvre le fichier spécifié par `nom_fichier` en mode écriture,
 * puis écrit le temps spécifié dans le fichier. Enfin, le fichier est fermé.
 *
 * @param nom_fichier Le chemin du fichier dans lequel enregistrer le temps.
 * @param temps Le temps à enregistrer dans le fichier.
 */
void enregistrer_temps_fichier(const char* nom_fichier, int temps)
{
    FILE* fichier = fopen(nom_fichier, "w");
    if (fichier != NULL)
    {
        fprintf(fichier, "%d", temps);
        fclose(fichier);
    }
}

/**
 * Charge le temps à partir d'un fichier.
 *
 * Cette fonction lit une valeur entière à partir du fichier spécifié et la retourne en tant que temps chargé.
 *
 * @param nom_fichier Le nom du fichier à partir duquel charger le temps.
 * @return La valeur du temps chargé.
 */
int charger_temps_fichier(const char* nom_fichier)
{
    int temps = 0;
    FILE* fichier = fopen(nom_fichier, "r");
    if (fichier != NULL)
    {
        fscanf(fichier, "%d", &temps);
        fclose(fichier);
    }
    return temps;
}

/**
 * Compare le temps donné avec le temps chargé à partir d'un fichier.
 * 
 * @param nom_fichier Le nom du fichier à partir duquel charger le temps.
 * @param temps Le temps à comparer.
 * @return true si le temps donné est inférieur au temps chargé à partir du fichier, sinon false.
 */
bool comparer_temps_fichier(const char* nom_fichier, int temps)
{
    int temps_fichier = charger_temps_fichier(nom_fichier);
    return temps < temps_fichier;
}


/**
 * Cette fonction permet de changer le temps enregistré dans un fichier.
 * Si le temps passé en paramètre est différent du temps enregistré dans le fichier,
 * la fonction enregistre le nouveau temps dans le fichier.
 *
 * @param nom_fichier Le chemin du fichier où le temps est enregistré.
 * @param temps Le nouveau temps à enregistrer dans le fichier.
 */
void changer_temps_fichier(const char* nom_fichier, int temps)
{
    if (comparer_temps_fichier(nom_fichier, temps))
    {
        enregistrer_temps_fichier(nom_fichier, temps);
    }
}
