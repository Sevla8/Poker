#ifndef JEU_H
#define JEU_H

#include "paquet.h"
#include "joueur.h"

struct Jeu {
	struct Paquet* paquet;
	struct Joueur* joueurs;
	int nb_joueurs;
	int premier;
};

#endif