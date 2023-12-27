#ifndef CHRONOMETRE_H
#define CHRONOMETRE_H

#define MINUTE 60
#define HEURE (MINUTE * 60)

void afficher_chronometre(int temps);
void changer_temps_fichier(const char *nom_fichier, int temps);
int charger_temps_fichier(const char *nom_fichier);

#endif // CHRONOMETRE_H
