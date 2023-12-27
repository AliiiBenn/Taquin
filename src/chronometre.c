#include <stdio.h>
#include <stdbool.h>

#define MINUTE 60
#define HEURE (MINUTE * 60)


void afficher_chronometre(int temps)
{
    int heures = temps / HEURE;
    int minutes = (temps % HEURE) / MINUTE;
    int secondes = temps % MINUTE;

    printf("%02d:%02d:%02d", heures, minutes, secondes);
}


void enregistrer_temps_fichier(const char* nom_fichier, int temps)
{
    FILE* fichier = fopen(nom_fichier, "w");
    if (fichier != NULL)
    {
        fprintf(fichier, "%d", temps);
        fclose(fichier);
    }
}

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

bool comparer_temps_fichier(const char* nom_fichier, int temps)
{
    int temps_fichier = charger_temps_fichier(nom_fichier);
    return temps < temps_fichier;
}


void changer_temps_fichier(const char* nom_fichier, int temps)
{
    if (comparer_temps_fichier(nom_fichier, temps))
    {
        enregistrer_temps_fichier(nom_fichier, temps);
    }
}
