#ifndef JOUEUR_H
#define JOUEUR_H

#include "carte.h"

struct Joueur {
	char* nom;
	int somme;
	int mise;
	struct Carte main[5];
	int nb_carte;
	int est_robot;
	int est_couche;
};

#endif